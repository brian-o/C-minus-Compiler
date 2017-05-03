.text	            		# Directive that says we are in code segment
	.globl main		#global declaration of function
main:			
	subu $sp, $sp, 36		# get some space in the stack for activation record
	sw  $ra, 4($sp)		# Store return adress into the stack
