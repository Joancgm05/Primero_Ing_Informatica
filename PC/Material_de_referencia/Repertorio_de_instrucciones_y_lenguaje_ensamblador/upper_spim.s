# Mips II Assembler 


# Data segment
	.data
max_bytes: .word 50
input_string: .asciiz "The Fermi paradox is mind blowing\n"
output_string: .space 50 # Reserve N bytes
	
# Text segment

	.text
	.globl main
main:
	la $a0,input_string
	la $a1,output_string
	lw $a2, max_bytes
	jal toupper
	# send output_string to the standard output
	la $a0,output_string
	li $v0,4
	syscall
	# Exit	
	li $v0,10
	syscall

#####################
# toupper function
	# Copy ascii string to a destination changing lowercase to uppercase.
	# The copy stops when N bytes are copied (plus zero to terminate) or zero
	# is reached in the source.
	# Input
	#$a0: source address
	#$a1: destination address
	#$a2: maximum number of chars to copy

	# Output
	# In memory
# Symbols and constants
	#.set r_saddr,$t1 
	#.set r_daddr,$t2
	#.set r_laddr,$t0
	#.set r_pchar,$t3
	#.set r_limit,$t4
	#.set LOWERLIMIT, 97
	#.set UPPERLIMIT,122
	#.set LOWUPDIF,32
toupper:
	move $t1,$a0 #move r_saddr,$a0
	move $t2,$a1 #move r_daddr,$a1
	addu $t0, $t2,$a2 #addu r_laddr,r_daddr,$a2
l_toupper_loop:
	ble $t0,$t2,l_toupper_end #ble r_laddr,r_daddr,l_toupper_end
	lbu $t3,0($t1) #lbu r_pchar,0(r_saddr)
	li $t4,97 #li r_limit,LOWERLIMIT
	blt $t3, $t4, l_toupper_copy #blt r_pchar,r_limit,l_toupper_copy
	li $t4,122 #li r_limit,UPPERLIMIT
	bgt $t3,$t4,l_toupper_copy #bgt r_pchar,r_limit,l_toupper_copy
	add $t3,$t3,-32 #addi r_pchar,r_pchar,-LOWUPDIF
l_toupper_copy:
	sb $t3,0($t2) #sb r_pchar,0(r_daddr)
	beq $t3,$zero,l_toupper_end #beq r_pchar,$zero,l_toupper_end
	addiu $t1,$t1,1 #addiu r_saddr,r_saddr,1
	addiu $t2,$t2,1 #addiu r_daddr,r_daddr,1
	j l_toupper_loop
l_toupper_end:
	sb $zero,0($t2) #sb $zero,0(r_daddr)
	jr $ra
########################
