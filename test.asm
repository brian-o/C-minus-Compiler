.text	            		# Directive that says we are in code segment
	.globl main		#global declaration of function
main:			
	subu $sp, $sp, 64		# get some space in the stack for activation record
	sw  $ra, 4($sp)		# Store return adress into the stack
	li  $t0, 33		#Load number into $t0 for if stmt
	li  $t2, 8		#Get base offset for ID
	li  $t3, 8		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t0, ($t2)		#Store the value in the right place
	li  $t0, 33		 #Load imeddiate into t0 FROM EXPR
	sw  $t0, 48($sp)		#store t0 to use later
	li  $t1, 11		 #Load immediate into t1 FROM EXPR
	lw  $t0, 48($sp)		#Get what was in t0 back form the stack
	add $t0, $t0, $t1		#add the LHS and RHS
	sw  $t0, 48($sp)		#put the value into the stack
	li  $t2, 8		#Get base offset for ID
	li  $t3, 12		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t0, ($t2)		#Store the value in the right place
	li  $t0, 55		#Load number into $t0 for if stmt
	li  $t0, 2		 #Load imeddiate into t0 FROM EXPR
	sw  $t0, 52($sp)		#store t0 to use later
	li  $t1, 2		 #Load immediate into t1 FROM EXPR
	lw  $t0, 52($sp)		#Get what was in t0 back form the stack
	add $t0, $t0, $t1		#add the LHS and RHS
	sw  $t0, 52($sp)		#put the value into the stack
	li  $t2, 8		#Load initial offset for the ID
	lw  $t3, 52($sp)		#Load array offset for the array
	sll $t3, $t3, 2		#Mutliply array offset by WORDSIZE
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t0, ($t2)		#Store the value in the right place
	li  $t0, 3		#Load number into $t0 for if stmt
	li  $t2, 8		#Get base offset for ID
	li  $t3, 4		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t0, ($t2)		#Store the value in the right place
	li  $t0, 66		#Load number into $t0 for if stmt
	li  $t2, 8		#Get base offset for ID
	li  $t3, 4		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 56($sp)		#store t0 to use later
	li  $t1, 2		 #Load immediate into t1 FROM EXPR
	lw  $t0, 56($sp)		#Get what was in t0 back form the stack
	add $t0, $t0, $t1		#add the LHS and RHS
	sw  $t0, 56($sp)		#put the value into the stack
	li  $t2, 8		#Load initial offset for the ID
	lw  $t3, 56($sp)		#Load array offset for the array
	sll $t3, $t3, 2		#Mutliply array offset by WORDSIZE
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	sw  $t0, ($t2)		#Store the value in the right place
	li  $t2, 8		#Get base offset for ID
	li  $t3, 8		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	lw  $a0, ($t2)		 #put stuff in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li  $t2, 8		#Get base offset for ID
	li  $t3, 12		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	lw  $a0, ($t2)		 #put stuff in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li  $t2, 8		#Get base offset for ID
	li  $t3, 16		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	lw  $a0, ($t2)		 #put stuff in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li  $t0, 2		 #Load imeddiate into t0 FROM EXPR
	sw  $t0, 60($sp)		#store t0 to use later
	li  $t1, 2		 #Load immediate into t1 FROM EXPR
	lw  $t0, 60($sp)		#Get what was in t0 back form the stack
	add $t0, $t0, $t1		#add the LHS and RHS
	sw  $t0, 60($sp)		#put the value into the stack
	li  $t2, 8		#Load initial offset for the ID
	lw  $t3, 60($sp)		#Load array offset for the array
	sll $t3, $t3, 2		#Mutliply array offset by WORDSIZE
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	lw  $a0, ($t2)		 #put stuff in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li  $t2, 8		#Get base offset for ID
	li  $t3, 20		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	lw  $a0, ($t2)		 #put stuff in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li  $v0, 0		#Return 0 from main
	lw  $ra, 4($sp)		# Load the right value back into ra
	addu $sp, $sp, 64		#add the right value back into sp
	jr  $ra		
