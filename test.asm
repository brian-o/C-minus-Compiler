.text	            		# Directive that says we are in code segment
	.globl foo		#global declaration of function
foo:			
	subu $t0, $sp, 8		# put where the new sp should be in t0
	sw  $ra, 4($t0)		# Store return adress into the stack
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	li  $a0, 1		# Write a Number to the screen
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li $v0, 42		#Load number into $v0 for return
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra		
	li $v0, 0		#Return 0 since there was no expression
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra		
.text	            		# Directive that says we are in code segment
	.globl main		#global declaration of function
main:			
	subu $t0, $sp, 12		# put where the new sp should be in t0
	sw  $ra, 4($t0)		# Store return adress into the stack
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	addu $t5, $sp, 0		#Save old sp into t5
	subu $sp, $sp, 8		#temoporarily move the sp to eval the args
	addu $sp, $t5, 0		#Put sp back where it goes
	jal foo		#jump and linkthe function
	nop		
	lw  $t0, ($v0)		#Get return for LHS
	sw  $t0, 8($sp)		#store t0 to use later
	li  $t1, 2		 #Load immediate into t1 FROM EXPR
	lw  $t0, 8($sp)		#Get what was in t0 back form the stack
	add $t0, $t0, $t1		#add the LHS and RHS
	sw  $t0, 8($sp)		#put the value into the stack
	lw  $a0, 8($sp)		 #fetch expr value
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li $v0, 0		#Return 0 since there was no expression
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra		
