.text	            		# Directive that says we are in code segment
	.globl sum		#global declaration of function
sum:			
	subu $t0, $sp, 24		# put where the new sp should be in t0
	sw  $ra, 4($t0)		# Store return adress into the stack
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 12($sp)		#store t0 to use later
	li  $t1, 0		 #Load immediate into t1 FROM EXPR
	lw  $t0, 12($sp)		#Get what was in t0 back form the stack
	slt $t0, $t1, $t0		#will be 1 if greater than
	sw  $t0, 12($sp)		#put the value into the stack
	beq $t0 $0 _L0		#If branch to else
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 20($sp)		#store t0 to use later
	li  $t2, 8		# Load ID offset into $t2
	add $t2, $t2, $sp		# Create exact mem location for ID
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 16($sp)		#store t0 to use later
	li  $t1, 1		 #Load immediate into t1 FROM EXPR
	lw  $t0, 16($sp)		#Get what was in t0 back form the stack
	sub $t0, $t0, $t1		#subtract the LHS and RHS
	sw  $t0, 16($sp)		#put the value into the stack
	lw  $t0, 16($sp)		#Insert the value from the arg expr into t0
	subu $t6, $sp, 24		# put where the new sp should be in t0
	sw  $sp, ($t6)		# save the old sp
	addu $sp, $t6, 0		#move the sp now
	sw  $t0 8($sp)		#store the value of arg into the stack
	lw  $sp, ($sp)		#Put sp back where it goes
	jal sum		#jump and linkthe function
	nop		#Program counter will be here when we return
	addu $t1, $v0, 0		#Get return for RHS
	lw  $t0, 20($sp)		#Get what was in t0 back form the stack
	add $t0, $t0, $t1		#add the LHS and RHS
	sw  $t0, 20($sp)		#put the value into the stack
	lw  $v0, 20($sp)		#load the value from the stack into v0 for return
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra		
	j   _L1		#finished if jump over else stmts
_L0:  			# ELSE target
_L1:    			# End of IF
	li $v0, 0		#Load number into $v0 for return
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra		
	li $v0, 0		#Return 0 since there was no expression
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra		
.text	            		# Directive that says we are in code segment
	.globl show		#global declaration of function
show:			
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
	subu $t0, $sp, 8		# put where the new sp should be in t0
	sw  $ra, 4($t0)		# Store return adress into the stack
	sw  $sp, ($t0)		# save the old sp
	addu $sp, $t0, 0		#move the sp now
	li  $t0, 5		 #Load imeddiate into t0 for arg
	subu $t6, $sp, 24		# put where the new sp should be in t0
	sw  $sp, ($t6)		# save the old sp
	addu $sp, $t6, 0		#move the sp now
	sw  $t0 8($sp)		#store the value of arg into the stack
	lw  $sp, ($sp)		#Put sp back where it goes
	jal sum		#jump and linkthe function
	nop		#Program counter will be here when we return
	addu $a0, $v0, 0		#put the return in a0 to write
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li  $t0, 42		 #Load imeddiate into t0 for arg
	subu $t6, $sp, 12		# put where the new sp should be in t0
	sw  $sp, ($t6)		# save the old sp
	addu $sp, $t6, 0		#move the sp now
	sw  $t0 8($sp)		#store the value of arg into the stack
	lw  $sp, ($sp)		#Put sp back where it goes
	jal show		#jump and linkthe function
	nop		#Program counter will be here when we return
	addu $t6, $v0, 0		#put the return in t6 to use later
	li $v0, 0		#Return 0 since there was no expression
	lw  $ra, 4($sp)		# Load the right value back into ra
	lw  $sp, ($sp)		#add the right value back into sp
	jr  $ra		
