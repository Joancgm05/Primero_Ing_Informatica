# Data
	.extern val1 8 
	.data 0x10000000
val1:	.word 0xDAFC00B3
	.word 0xAABBCCDD
	.text
	.globl main
main:	
	lw $t0,val1
	lw $t0,val1+4
	jr $ra
