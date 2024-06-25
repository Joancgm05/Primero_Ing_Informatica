
	.data
length:	.word	3
vector:	.float	100.0,-439.0,300.0
factor:	.float	10.0

	.text
	.globl main
main:
	la $a0,length
	la $a1,vector
	la $a2,factor
	jal svector
	li $a0,0
	li $v0,10
	syscall

##################
# svector function
########
	# Multiply a floating point vector by a floating point scalar
	# Input
	# $a0 Number of elements of vector
	# $a1 Vector address
	# $a2 Scale factor address
	# Output
	# In memory the scaled vector
	
	#
	#.set r_vector $t1
	#.set r_length $t0 #Length in bytes
	#.set r_factor $f2 
	#.set r_laddr $t3
	#.set r_vcomponent $f4
	
	
svector:
	lw $t0,0($a0) #lw r_length,0($a0) #Length
	sll $t0,$t0,2 #sll r_length,r_length,2 #Mult by 4
	move $t1,$a1 #move r_vector,$a1 #vector
	lwc1 $f2,0($a2) #lwc1 r_factor,0($a2) #Factor
	add $t3,$a1,$t0 #add r_laddr,$a1,r_length #Dir limite
l_svector_loop:
	bge $t1,$t3,l_svector_end #bge r_vector,r_laddr,l_svector_end
	lwc1 $f4,0($t1) #lwc1 r_vcomponent,0(r_vector)
	mul.s $f4,$f4,$f2  #mul.s r_vcomponent,r_vcomponent,r_factor
	swc1 $f4,0($t1) #swc1 r_vcomponent,0(r_vector)
	addiu $t1,$t1,4 #addiu r_vector,r_vector,4
	j l_svector_loop
l_svector_end:
	jr $ra
