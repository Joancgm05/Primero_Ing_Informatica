	.data
refvalue: .word 10
length: .word 3
vector: .word 20 -30 -20

	.text
	.globl main
main:
	lw $a0,length
	la $a1,vector
	lw $a2,refvalue
	jal sumabs
	move $a0,$v0
	li $v0,1
	syscall
	li $a0,0
	li $v0,10
	syscall

###############
# fabs 
###############
# Input
# $a0: integer value
# $a1: integer reference value
# Output
# $v0: integer (abs of input value - ref. value)
fabs:
	sub $a0,$a0,$a1
	# This is an alternative to the abs pseudo instruction
	bgez $a0, l_abs_fin
	xor $a0,$a0,0xffffffff
	addiu $a0,$a0,1
l_abs_fin:
	move $v0,$a0
	jr $ra
	
################
# sumabs
#################
# Input:
# $a0 : number of vector components
# $a1: vector address
# $a2 : reference value
# Output:
# $v0: sum of the absolute value of components

# $s0 r_sum
# $s1 r_compaddr
# $s2 r_limaddr
# $a1 r_refvalue
sumabs:
	#Preambulo
	addi $sp,$sp,-16
	sw $ra,0($sp)
	sw $s0,4($sp)
	sw $s1,8($sp)
	sw $s2,12($sp)
	
	li $s0,0 # li r_sum,0
	blez $a0,l_sumabs_end
	move $s1,$a1 #move r_compaddr,$a1
	sll $a0,$a0,2
	addu $s2,$a1,$a0 # addiu r_limaddr,r_vaddr,r_length
	move $a1,$a2
l_sumabs_loop:
	lw $a0,0($s1) #lw r_comp,0(r_compaddr)
	jal fabs
	addu $s0,$s0,$v0 # addu r_sum, r_sum,$v0
	addiu $s1,$s1,4 #addiu r_compaddr,r_compaddr,1
	blt $s1,$s2,l_sumabs_loop #blt $r_compaddr,r_limaddr,l_sumabs_loop
l_sumabs_end:
	#Salida
	move $v0,$s0
	# Epilogo
	lw $ra,0($sp)
	lw $s0,4($sp)
	lw $s1,8($sp)
	lw $s2,12($sp)
	addi $sp,$sp,16
	jr $ra
