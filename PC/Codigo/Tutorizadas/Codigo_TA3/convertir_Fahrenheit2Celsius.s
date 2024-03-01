# Programa para convertir de grados Fahrenheit a Celsius
# Usa la fórmula C = (F - 32)/1.8
	.data
str_pideF:	.asciiz	"Introduzca grados Fahrenheit (entero): "
str_celsius:	.asciiz	"Temperatura en grados Celsius: "
factor:		.float	1.8
	.text
main:
	# Sacamos cadena de petición de Fahrenheit
	li	$v0,4
	la	$a0,str_pideF
	syscall
	# Esperamos a que se introduzca un entero
	li	$v0,5
	syscall
	move	$s0,$v0    	# Valor recibido a registro salvado $s0
	# Pasamos entero a float
	mtc1	$s0,$f20	# $f20 = $s0
	cvt.s.w	$f22,$f20	# $f22 = $f20
	# Hacemos la operación
	li.s	$f4,32.0	# $f4 = 32.0
	sub.s	$f24,$f22,$f4	# $f24 = $f22 - $f4
	l.s	$f4,factor	# $f4 = 1.8
	div.s	$f24,$f24,$f4	# $f24 = $f24 / $f4
	# Mostramos resultado con mensaje previo
	li	$v0,4
	la	$a0,str_celsius
	syscall
	# Imprimimos el resultado
	li	$v0,2
	mov.s	$f12,$f24
	syscall
	# Terminamos el programa
	li	$v0,10
	syscall
	
	
