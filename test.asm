.text	            		# Directive that says we are in code segment
	.globl foo		#global declaration of function
foo:			
	subu $t0, $sp, 12		# put where the new sp should be in t0
	sw  $ra, 4($t0)		# Store return adress into the stack
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $a0, ($t2)		 #put id value in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
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
	li  $t6 5		#Load number into $t6 for if stmt
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	sw  $t6, ($t2)		#Store the value in the right place
	subu $t0, $sp, 12		# put where the new sp should be in t0
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #arg is an ID load into t0
	sw  $t0 8($sp)		#store the value of arg into the stack
	lw  $sp, ($sp)		#Put sp back where it goes
	jal foo		#jump and linkthe function
	nop		
	addu $t6, $v0, 0		#put the return in t6 to use later
	li $v0, 0		#Return 0 since there was no expression
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra		
