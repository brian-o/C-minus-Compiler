.text	            		# Directive that says we are in code segment
	.globl main		#global declaration of function
main:			
	subu $t0, $sp, 8		# put where the new sp should be in t0
	sw  $ra, 4($t0)		# Store return adress into the stack
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	li  $a0, 42		# Write a Number to the screen
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li $v0, 0		#Return 0 since there was no expression
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra		
