# Programa que hace la suma de dos enteros introducidos
	.data 	# Seccion declaracion de datos
cadpet:		.asciiz	"Introduza un entero: "
cadsuma:	.asciiz	"La suma es: "

	.text	# Seccion de codigo de usuario
main:
	# Se imprime mensaje para introducir primer entero
	li	$v0,4		# $v0=4 funcion print string
	la	$a0,cadpet	# $a0= direccion de la cadena a imprimir
	syscall
	# leo el primer entero y lo almaceno en $s0
	li	$v0,5		# $v0=5 funcion leer un entero.
	syscall			# el entero leido se queda en $v0
	move	$s0,$v0		# almaceno en $s0 el primer entero leido.
	# Se imprime mensaje para introducir segundo entero
	li	$v0,4		# $v0=4 funcion print string
	la	$a0,cadpet	# $a0= direccion de la cadena a imprimir
	syscall
	# leo el segundo entero y lo almaceno en $s1
	li	$v0,5		# $v0=5 funcion print string
	syscall			# el entero leido se queda en $v0
	move	$s1,$v0		#almaceno en $s1 el segundo entero leido.
	
	add	$s3,$s0,$s1	#almaceno en $s3 la suma de los dos enteros
	# Se imprime cadena resultado, el entero suma y un salto de línea
	li	$v0,4		# $v0=4 funcion print_string
	la	$a0,cadsuma	# $a0= direccion de la cadena a imprimir
	syscall
	li	$v0,1		# $v0=4 funcion print_int
	move	$a0,$s3		# $a0=entero a imprimir
	syscall
	li	$v0,11		# $v0=11 funcion print_char
	li	$a0,'\n'	# $a0=caracter a imprimir → salto de línea
	syscall
	# se hace una salida limpia del sistema (exit es codigo 10)
	li	$v0,10
	syscall


