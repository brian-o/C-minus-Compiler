.text	            		# Directive that says we are in code segment
	.globl f		#global declaration of function
f:			
	subu $t0, $sp, 16		# put where the new sp should be in t0
	sw  $ra, 4($t0)		# Store return adress into the stack
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	li  $t6, 6		#Load number into $t6 for expr stmt
	sw $t6, 12($sp)		#put the value in the write place for later
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw $t6, 12($sp)		#sget the value back formt he stack
	sw  $t6, ($t2)		#Store the value in the right place
	li $v0, 1		#Load number into $v0 for return
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
	subu $t0, $sp, 28		# put where the new sp should be in t0
	sw  $ra, 4($t0)		# Store return adress into the stack
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	li  $t6, 5		#Load number into $t6 for expr stmt
	sw $t6, 24($sp)		#put the value in the write place for later
	jal f		#jump and linkthe function
	nop		#Program counter will be here when we return
	addu $t3, $v0, 0		#Move return value into t3
	sll $t3, $t3, 2		#Mutliply array offset by WORDSIZE
	li  $t2, 8		#Load initial offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	lw $t6, 24($sp)		#sget the value back formt he stack
	sw  $t6, ($t2)		#Store the value in the right place
	li  $t2, 8		#Get base offset for ID
	li  $t3, 4		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID offset
	add $t2, $t2, $sp		#Add the stack poitner in
	lw  $a0, ($t2)		 #put id value in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li $v0, 0		#Return 0 since there was no expression
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra		
