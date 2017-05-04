	.data		#Indicates we are in data segment
a: .space  4			
	.data		#Indicates we are in data segment
bb: .space  400			
.text	            		# Directive that says we are in code segment
	.globl main		#global declaration of function
main:			
	subu $sp, $sp, 404		# get some space in the stack for activation record
	sw  $ra, 4($sp)		# Store return adress into the stack
	li  $t6 42		#Load number into $t6 for if stmt
	la  $t2, a		# Load ID from data segment into $t2
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6 66		#Load number into $t6 for if stmt
	la  $t2, bb		#Get ID address from data segment
	li  $t3, 168		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID address
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6 0		#Load number into $t6 for if stmt
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6 1		#Load number into $t6 for if stmt
	li  $t2, 12		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6 99		#Load number into $t6 for if stmt
	li  $t0, 1		 #Load imeddiate into t0 FROM EXPR
	sw  $t0, 140($sp)		#store t0 to use later
	li  $t1, 2		 #Load immediate into t1 FROM EXPR
	lw  $t0, 140($sp)		#Get what was in t0 back form the stack
	add $t0, $t0, $t1		#add the LHS and RHS
	sw  $t0, 140($sp)		#put the value into the stack
	li  $t2, 20		#Load initial offset for the ID
	lw  $t3, 140($sp)		#Load array offset for the array
	sll $t3, $t3, 2		#Mutliply array offset by WORDSIZE
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t2, 20		#Get base offset for ID
	li  $t3, 12		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	lw  $a0, ($t2)		 #put stuff in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	la  $t2, a		# Load ID from data segment into $t2
	lw  $a0, ($t2)		 #put stuff in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li  $t0, 400		 #Load imeddiate into t0 FROM EXPR
	sw  $t0, 144($sp)		#store t0 to use later
	li  $t1, 10		 #Load immediate into t1 FROM EXPR
	lw  $t0, 144($sp)		#Get what was in t0 back form the stack
	div $t0, $t1		#Divide LHS and RHS
	mflo $t0		#move contents of hi into $t0
	sw  $t0, 144($sp)		#put the value into the stack
	lw  $t0, 144($sp)		#Insert the value from the LHS EXPR into t0
	sw  $t0, 156($sp)		#store t0 to use later
	li  $t0, 4		 #Load imeddiate into t0 FROM EXPR
	sw  $t0, 148($sp)		#store t0 to use later
	li  $t1, 2		 #Load immediate into t1 FROM EXPR
	lw  $t0, 148($sp)		#Get what was in t0 back form the stack
	mult $t0, $t1		#Multiply the LHS and RHS
	mflo $t0		#move contents of lo int $t0
	sw  $t0, 148($sp)		#put the value into the stack
	lw  $t0, 148($sp)		#Insert the value from the LHS EXPR into t0
	sw  $t0, 152($sp)		#store t0 to use later
	li  $t1, 6		 #Load immediate into t1 FROM EXPR
	lw  $t0, 152($sp)		#Get what was in t0 back form the stack
	sub $t0, $t0, $t1		#subtract the LHS and RHS
	sw  $t0, 152($sp)		#put the value into the stack
	lw  $t1, 152($sp)		#Insert the value from the RHS EXPR into t1
	lw  $t0, 156($sp)		#Get what was in t0 back form the stack
	add $t0, $t0, $t1		#add the LHS and RHS
	sw  $t0, 156($sp)		#put the value into the stack
	la  $t2, bb		#Get ID address from data segment
	lw  $t3, 156($sp)		#Load array offset
	sll $t3, $t3, 2		#Mutliply array offset by WORDSIZE
	add $t2, $t2, $t3		#Add array offset to ID address
	lw  $a0, ($t2)		 #put stuff in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		#Load the value from the stack into t0 for ifstmt
	beq $t0 $0 _L0		#If branch to else
	li  $a0, 101		# Write a Number to the screen
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	j   _L1		#finished if jump over else stmts
_L0:  			# ELSE target
	li  $a0, 77		# Write a Number to the screen
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
_L1:    			# End of IF
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 160($sp)		#store t0 to use later
	li  $t2, 12		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t1, ($t2)		 #RHS is an ID load into t0
	lw  $t0, 160($sp)		#Get what was in t0 back form the stack
	slt $t0, $t0, $t1		#will be 1 if less than
	sw  $t0, 160($sp)		#put the value into the stack
	beq $t0 $0 _L2		#If branch to else
	li  $a0, 55		# Write a Number to the screen
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	j   _L3		#finished if jump over else stmts
_L2:  			# ELSE target
_L3:    			# End of IF
_L4: 	   		#Beginning of WHILE target
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 164($sp)		#store t0 to use later
	li  $t1, 10		 #Load immediate into t1 FROM EXPR
	lw  $t0, 164($sp)		#Get what was in t0 back form the stack
	slt $t0, $t0, $t1		#will be 1 if less than
	sw  $t0, 164($sp)		#put the value into the stack
	beq $t0 $0 _L5		#WHILE expression false jump out
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $a0, ($t2)		 #put stuff in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 168($sp)		#store t0 to use later
	li  $t1, 1		 #Load immediate into t1 FROM EXPR
	lw  $t0, 168($sp)		#Get what was in t0 back form the stack
	add $t0, $t0, $t1		#add the LHS and RHS
	sw  $t0, 168($sp)		#put the value into the stack
	lw  $t6, 168($sp)		#load the value from the stack into t6
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	sw  $t6, ($t2)		#Store the value in the right place
	j   _L4		#jump back to beginning of WHILE
_L5:  	  		#target to stop executing loop
	li  $t6 0		#Load number into $t6 for if stmt
	li  $t2, 16		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	sw  $t6, ($t2)		#Store the value in the right place
_L6: 	   		#Beginning of WHILE target
	li  $t2, 16		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 168($sp)		#store t0 to use later
	li  $t1, 10		 #Load immediate into t1 FROM EXPR
	lw  $t0, 168($sp)		#Get what was in t0 back form the stack
	slt $t0, $t0, $t1		#will be 1 if less than
	sw  $t0, 168($sp)		#put the value into the stack
	beq $t0 $0 _L7		#WHILE expression false jump out
	li  $t2, 16		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 172($sp)		#store t0 to use later
	li  $t1, 2		 #Load immediate into t1 FROM EXPR
	lw  $t0, 172($sp)		#Get what was in t0 back form the stack
	div $t0, $t1		#Divide LHS and RHS
	mflo $t0		#move contents of hi into $t0
	sw  $t0, 172($sp)		#put the value into the stack
	lw  $t0, 172($sp)		#Insert the value from the LHS EXPR into t0
	sw  $t0, 176($sp)		#store t0 to use later
	li  $t1, 2		 #Load immediate into t1 FROM EXPR
	lw  $t0, 176($sp)		#Get what was in t0 back form the stack
	addu $t0, $t0, 1		#add one for GT equal
	slt $t0, $t1, $t0		#will be 1 if GT equal
	sw  $t0, 176($sp)		#put the value into the stack
	beq $t0 $0 _L8		#If branch to else
	li  $a0, 40		# Write a Number to the screen
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	j   _L9		#finished if jump over else stmts
_L8:  			# ELSE target
	li  $a0, 20		# Write a Number to the screen
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
_L9:    			# End of IF
	li  $t2, 16		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 180($sp)		#store t0 to use later
	li  $t1, 1		 #Load immediate into t1 FROM EXPR
	lw  $t0, 180($sp)		#Get what was in t0 back form the stack
	add $t0, $t0, $t1		#add the LHS and RHS
	sw  $t0, 180($sp)		#put the value into the stack
	lw  $t6, 180($sp)		#load the value from the stack into t6
	li  $t2, 16		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	sw  $t6, ($t2)		#Store the value in the right place
	j   _L6		#jump back to beginning of WHILE
_L7:  	  		#target to stop executing loop
	li  $v0, 0		#Return 0 from main
	lw  $ra, 4($sp)		# Load the right value back into ra
	addu $sp, $sp, 404		#add the right value back into sp
	jr  $ra		
