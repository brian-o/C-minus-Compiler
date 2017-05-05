.text	            		# Directive that says we are in code segment
	.globl f		#global declaration of function
f:
	subu $t0, $sp, 16		# put where the new sp should be in t0
	sw  $ra, 4($t0)		# Store return adress into the stack
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $a0, ($t2)		 #put id value in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall
	li  $t2, 12		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $a0, ($t2)		 #put id value in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li $v0, 0		#Return 0 since there was no expression
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra
.text	            		# Directive that says we are in code segment
	.globl ret42		#global declaration of function
ret42:
	subu $t0, $sp, 8		# put where the new sp should be in t0
	sw  $ra, 4($t0)		# Store return adress into the stack
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	li $v0, 42		#Load number into $v0 for return
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra
	li $v0, 0		#Return 0 since there was no expression
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra
.text	            		# Directive that says we are in code segment
	.globl doubleit		#global declaration of function
doubleit:
	subu $t0, $sp, 16		# put where the new sp should be in t0
	sw  $ra, 4($t0)		# Store return adress into the stack
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	li  $t0, 2		 #Load imeddiate into t0 FROM EXPR
	sw  $t0, 12($sp)		#store t0 to use later
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t1, ($t2)		 #RHS is an ID load into t1
	lw  $t0, 12($sp)		#Get what was in t0 back form the stack
	mult $t0, $t1		#Multiply the LHS and RHS
	mflo $t0		#move contents of lo int $t0
	sw  $t0, 12($sp)		#put the value into the stack
	lw  $v0, 12($sp)		#load the value from the stack into v0 for return
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra
	li $v0, 0		#Return 0 since there was no expression
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra
	.data		#Indicates we are in data segment
on: .space  4
	.data		#Indicates we are in data segment
off: .space  20
.text	            		# Directive that says we are in code segment
	.globl main		#global declaration of function
main:
	subu $t0, $sp, 92		# put where the new sp should be in t0
	sw  $ra, 4($t0)		# Store return adress into the stack
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	li  $t6, 10		#Load number into $t6 for expr stmt
	li  $t2, 12		#Get base offset for ID
	li  $t3, 0		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6, 11		#Load number into $t6 for expr stmt
	li  $t2, 12		#Get base offset for ID
	li  $t3, 4		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6, 22		#Load number into $t6 for expr stmt
	li  $t2, 12		#Get base offset for ID
	li  $t3, 8		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6, 33		#Load number into $t6 for expr stmt
	li  $t2, 12		#Get base offset for ID
	li  $t3, 12		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6, 44		#Load number into $t6 for expr stmt
	li  $t2, 12		#Get base offset for ID
	li  $t3, 16		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6, 55		#Load number into $t6 for expr stmt
	li  $t2, 12		#Get base offset for ID
	li  $t3, 20		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6, 66		#Load number into $t6 for expr stmt
	li  $t2, 12		#Get base offset for ID
	li  $t3, 24		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6, 77		#Load number into $t6 for expr stmt
	li  $t2, 12		#Get base offset for ID
	li  $t3, 28		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6, 88		#Load number into $t6 for expr stmt
	li  $t2, 12		#Get base offset for ID
	li  $t3, 32		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6, 99		#Load number into $t6 for expr stmt
	li  $t2, 12		#Get base offset for ID
	li  $t3, 36		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t6, 5		#Load number into $t6 for expr stmt
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	sw  $t6, ($t2)		#Store the value in the right place
	subu $t0, $sp, 16		# put where the new sp should be in t0
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	addu $sp, $sp, 16		#move sp up temporarily
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #arg is an ID load into t0
	subu $sp, $sp, 16		#move sp back where it goes
	sw  $t0 8($sp)		#store the value of arg into the stack
	li  $t0, 9		 #Load imeddiate into t0 for arg
	sw  $t0 12($sp)		#store the value of arg into the stack
	lw  $sp, ($sp)		#Put sp back where it goes
	jal f		#jump and linkthe function
	nop
	addu $t6, $v0, 0		#put the return in t6 to use later
	li  $t6, 3		#Load number into $t6 for expr stmt
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	sw  $t6, ($t2)		#Store the value in the right place
	subu $t0, $sp, 16		# put where the new sp should be in t0
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	addu $sp, $sp, 16		#move sp up temporarily
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #arg is an ID load into t0
	subu $sp, $sp, 16		#move sp back where it goes
	sw  $t0 8($sp)		#store the value of arg into the stack
	subu $t0, $sp, 16		# put where the new sp should be in t0
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	li  $t0, 6		 #Load imeddiate into t0 for arg
	sw  $t0 8($sp)		#store the value of arg into the stack
	li  $t0, 9		 #Load imeddiate into t0 for arg
	sw  $t0 12($sp)		#store the value of arg into the stack
	lw  $sp, ($sp)		#Put sp back where it goes
	jal f		#jump and linkthe function
	nop
	addu $t0, $v0, 0		#Get return for arg into t0
	sw  $t0 12($sp)		#store the value of arg into the stack
	lw  $sp, ($sp)		#Put sp back where it goes
	jal f		#jump and linkthe function
	nop
	addu $t6, $v0, 0		#put the return in t6 to use later
	jal ret42		#jump and linkthe function
	nop
	addu $t6, $v0, 0		#put the return in t6 to use later
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $a0, ($t2)		 #put id value in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall
	subu $t0, $sp, 16		# put where the new sp should be in t0
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	addu $sp, $sp, 16		#move sp up temporarily
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #arg is an ID load into t0
	subu $sp, $sp, 16		#move sp back where it goes
	sw  $t0 8($sp)		#store the value of arg into the stack
	lw  $sp, ($sp)		#Put sp back where it goes
	jal doubleit		#jump and linkthe function
	nop
	addu $t6, $v0, 0		#put the return in t6 to use later
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $a0, ($t2)		 #put id value in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall
	subu $t0, $sp, 16		# put where the new sp should be in t0
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	addu $sp, $sp, 16		#move sp up temporarily
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #arg is an ID load into t0
	subu $sp, $sp, 16		#move sp back where it goes
	sw  $t0 8($sp)		#store the value of arg into the stack
	lw  $sp, ($sp)		#Put sp back where it goes
	jal doubleit		#jump and linkthe function
	nop
	addu $a0, $v0, 0		#put the return in a0 to write
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall
	jal ret42		#jump and linkthe function
	nop
	addu $t6, $v0, 0		#put the return in t6 to use later
	la  $t2, on		# Load ID from data segment into $t2
	sw  $t6, ($t2)		#Store the value in the right place
	la  $t2, on		# Load ID from data segment into $t2
	lw  $a0, ($t2)		 #put id value in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall
	la  $t2, on		# Load ID from data segment into $t2
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 52($sp)		#store t0 to use later
	li  $t2, 12		#Get base offset for ID
	li  $t3, 0		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	lw  $t1, ($t2)		 #RHS is an ID load into t1
	lw  $t0, 52($sp)		#Get what was in t0 back form the stack
	sub $t0, $t0, $t1		#subtract the LHS and RHS
	sw  $t0, 52($sp)		#put the value into the stack
	lw  $t0, 52($sp)		#Insert the value from the LHS EXPR into t0
	sw  $t0, 56($sp)		#store t0 to use later
	li  $t2, 12		#Get base offset for ID
	li  $t3, 4		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	lw  $t1, ($t2)		 #RHS is an ID load into t1
	lw  $t0, 56($sp)		#Get what was in t0 back form the stack
	sub $t0, $t0, $t1		#subtract the LHS and RHS
	sw  $t0, 56($sp)		#put the value into the stack
	lw  $t6, 56($sp)		#load the value from the stack into t6
	la  $t2, on		# Load ID from data segment into $t2
	sw  $t6, ($t2)		#Store the value in the right place
	la  $t2, on		# Load ID from data segment into $t2
	lw  $a0, ($t2)		 #put id value in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall
	la  $t2, on		# Load ID from data segment into $t2
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 60($sp)		#store t0 to use later
	li  $t1, 42		 #Load immediate into t1 FROM EXPR
	lw  $t0, 60($sp)		#Get what was in t0 back form the stack
	slt $t0, $t0, $t1		#will be 1 if less than
	sw  $t0, 60($sp)		#put the value into the stack
	lw  $a0, 60($sp)		 #fetch expr value
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall
	la  $t2, on		# Load ID from data segment into $t2
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 64($sp)		#store t0 to use later
	li  $t1, 42		 #Load immediate into t1 FROM EXPR
	lw  $t0, 64($sp)		#Get what was in t0 back form the stack
	slt $t0, $t1, $t0		#will be 1 if greater than
	sw  $t0, 64($sp)		#put the value into the stack
	lw  $a0, 64($sp)		 #fetch expr value
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall
	li  $t6, 0		#Load number into $t6 for expr stmt
	la  $t2, on		# Load ID from data segment into $t2
	sw  $t6, ($t2)		#Store the value in the right place
	la  $t2, on		# Load ID from data segment into $t2
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 68($sp)		#store t0 to use later
	li  $t1, 0		 #Load immediate into t1 FROM EXPR
	lw  $t0, 68($sp)		#Get what was in t0 back form the stack
	seq $t0, $t0, $t1		#If equal will be 1
	sw  $t0, 68($sp)		#put the value into the stack
	beq $t0 $0 _L0		#If branch to else
	li  $a0, 123		# Write a Number to the screen
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall
	j   _L1		#finished if jump over else stmts
_L0:  			# ELSE target
	li  $a0, 456		# Write a Number to the screen
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall
_L1:    			# End of IF
	li  $t6, 10		#Load number into $t6 for expr stmt
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	sw  $t6, ($t2)		#Store the value in the right place
_L2: 	   		#Beginning of WHILE target
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 72($sp)		#store t0 to use later
	li  $t1, 0		 #Load immediate into t1 FROM EXPR
	lw  $t0, 72($sp)		#Get what was in t0 back form the stack
	addu $t0, $t0, 1		#add one for GT equal
	slt $t0, $t1, $t0		#will be 1 if GT equal
	sw  $t0, 72($sp)		#put the value into the stack
	beq $t0 $0 _L3		#WHILE expression false jump out
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $a0, ($t2)		 #put id value in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 76($sp)		#store t0 to use later
	li  $t1, 1		 #Load immediate into t1 FROM EXPR
	lw  $t0, 76($sp)		#Get what was in t0 back form the stack
	sub $t0, $t0, $t1		#subtract the LHS and RHS
	sw  $t0, 76($sp)		#put the value into the stack
	lw  $t6, 76($sp)		#load the value from the stack into t6
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	sw  $t6, ($t2)		#Store the value in the right place
	j   _L2		#jump back to beginning of WHILE
_L3:  	  		#target to stop executing loop
_L4: 	   		#Beginning of WHILE target
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 80($sp)		#store t0 to use later
	li  $t2, 12		#Get base offset for ID
	li  $t3, 20		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 76($sp)		#store t0 to use later
	li  $t1, 5		 #Load immediate into t1 FROM EXPR
	lw  $t0, 76($sp)		#Get what was in t0 back form the stack
	div $t0, $t1		#Divide LHS and RHS
	mflo $t0		#move contents of hi into $t0
	sw  $t0, 76($sp)		#put the value into the stack
	lw  $t1, 76($sp)		#Insert the value from the RHS EXPR into t1
	lw  $t0, 80($sp)		#Get what was in t0 back form the stack
	addu $t1, $t1, 1		#Add one for the lt equal
	slt $t0, $t0, $t1		#Will be 1 if LT equal
	sw  $t0, 80($sp)		#put the value into the stack
	beq $t0 $0 _L5		#WHILE expression false jump out
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $a0, ($t2)		 #put id value in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 88($sp)		#store t0 to use later
	li  $t2, 12		#Get base offset for ID
	li  $t3, 0		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 84($sp)		#store t0 to use later
	li  $t1, 10		 #Load immediate into t1 FROM EXPR
	lw  $t0, 84($sp)		#Get what was in t0 back form the stack
	div $t0, $t1		#Divide LHS and RHS
	mflo $t0		#move contents of hi into $t0
	sw  $t0, 84($sp)		#put the value into the stack
	lw  $t1, 84($sp)		#Insert the value from the RHS EXPR into t1
	lw  $t0, 88($sp)		#Get what was in t0 back form the stack
	add $t0, $t0, $t1		#add the LHS and RHS
	sw  $t0, 88($sp)		#put the value into the stack
	lw  $t6, 88($sp)		#load the value from the stack into t6
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	sw  $t6, ($t2)		#Store the value in the right place
	j   _L4		#jump back to beginning of WHILE
_L5:  	  		#target to stop executing loop
	li $v0, 0		#Return 0 since there was no expression
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra
