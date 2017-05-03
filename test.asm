	.data		#Indicates we are in data segment
x: .space  4			
	.data		#Indicates we are in data segment
y: .space  160			
.text	            		# Directive that says we are in code segment
	.globl main		#global declaration of function
main:			
	subu $sp, $sp, 164		# get some space in the stack for activation record
	sw  $ra, 4($sp)		# Store return adress into the stack
	li  $t0, 5		#Load number into $t0 for if stmt
	la  $t2, x		# Load ID from data segment into $t2
	sw  $t0, ($t2)		#Store the value in the right place
	li  $t0, 42		#Load number into $t0 for if stmt
	la  $t2, y		#Get ID address from data segment
	li  $t3, 24		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID address
	sw  $t0, ($t2)		#Store the value in the right place
	la  $t2, x		# Load ID from data segment into $t2
	lw  $a0, ($t2)		 #put stuff in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	la  $t2, y		#Get ID address from data segment
	li  $t3, 24		#Get array offset for the ID
	add $t2, $t2, $t3		#Add array offset to ID address
	lw  $a0, ($t2)		 #put stuff in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	la  $t2, x		# Load ID from data segment into $t2
	lw  $t0, ($t2)		 #LHS is an ID load into t0
	sw  $t0, 8($sp)		#store t0 to use later
	li  $t1, 1		 #Load immediate into t1 FROM EXPR
	lw  $t0, 8($sp)		#Get what was in t0 back form the stack
	add $t0, $t0, $t1		#add the LHS and RHS
	sw  $t0, 8($sp)		#put the value into the stack
	la  $t2, x		# Load ID from data segment into $t2
	sw  $t0, ($t2)		#Store the value in the right place
	la  $t2, x		# Load ID from data segment into $t2
	lw  $a0, ($t2)		 #put stuff in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	la  $t2, x		# Load ID from data segment into $t2
	lw  $t3, ($t2)		#Move the ID value out of the way
	sll $t3, $t3, 2		#Mutliply array offset by WORDSIZE
	la  $t2, y		#Get ID address from data segment
	add $t2, $t2, $t3		#Add array offset to ID address
	lw  $a0, ($t2)		 #put stuff in a0
	li  $v0, 1		 #put 1 in v0 to print an integer
	syscall		
	li  $v0, 0		#Return 0 from main
	lw  $ra, 4($sp)		# Load the right value back into ra
	addu $sp, $sp, 164		#add the right value back into sp
	jr  $ra		
