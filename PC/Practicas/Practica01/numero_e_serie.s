# PR1. PRINCIPIO DE COMPUTADORES.
# Autor: Joan Carlos García Méndez
# Fecha ultima modificacion: 01/03/2024
# Descripción: Programa que calcula la serie del número e.
#include <iostream>
#include <iomanip>

#int main(int argc, char *argv[])

#  double error = 0;
#  double e = 1; // 1/0!
#  double fact = 1; // 0!
#  double numterminos = 1;
#  double ultimo_termino = 1; ; // 1/0!

#  std::cout << "\nPR1: Principio de computadores.\n";
#  do {
#      std::cout << "\nIntroduzca maximo error permitido: ";
#      std::cin >> error;
#      if (!(error >= 0.00001 && error < 1))
#          std::cout << "\nError: el dato introducido debe cumplir 0.00001 <= dato < 1\n";
#      else break;
#  } while (true);

#  while (ultimo_termino >= error) {
#      fact *= numterminos;
#      ultimo_termino = 1/fact;
#      e += ultimo_termino;
#      numterminos++;
#  }
#  std::cout <<  "\nNumero e: ";
#  std::cout << std::fixed << std::setprecision(17) << e;
#  std::cout << "\nNumero de terminos: " << int(numterminos);
#  std::cout << "\nPR1: Fin del programa.\n";
#  return 0;
#}
	.data

titulo:		.asciiz "\nPR1: Principio de computadores.\n"
pet:		.asciiz "\nIntroduzca maximo error permitido: "
caderr:		.asciiz "\nError: el dato introducido debe cumplir 0.00001 <= dato < 1\n"
cade:		.asciiz "\nNumero e: "
cadnt:		.asciiz "\nNumero de terminos: "
cadfin:		.asciiz "\nPR1: Fin del programa.\n"

# Asignación de variables a registros
# error 			-> $f20
# e 				-> $f22
# fact				-> $f24
# numterminos  		-> $f26
# ultimo_termino	-> $f28

	.text

main:

	#  std::cout << "\nPR1: Principio de computadores.\n";
	li		$v0, 4				# $v0=4 funcion print string
	la 		$a0, titulo			# $a0= direccion de la cadena a imprimir
	syscall
	b 		do					# Salto al do	

error:
	# std::cout << "\nError: el dato introducido debe cumplir 0.00001 <= dato < 1" << std::endl;
	li 			$v0, 4			# $v0=4 funcion print string
	la			$a0, caderr		# $a0= direccion de la cadena a imprimir
	syscall

# bucle do-while
# Comienzo del do
# do{
do:
	# std::cout << "\nIntroduzca maximo error permitido: ";
	li			$v0, 4 			# $v0=4 funcion print string
	la			$a0, pet		# $a0= direccion de la cadena a imprimir
	syscall
	# std::cin >> error;
	li 			$v0, 7			# $v0=7 funcion read double
	syscall
	mov.d 		$f20, $f0

	# if (!(error >= 0.00001 && error < 1))
	li.d		$f4, 0.00001 	# carga inmediata a doble precision
	c.lt.d 		$f20, $f4		# Si $f20 < $f4
	bc1t		error			# salto a error
	li.d 		$f6, 1.0		# carga inmediata a doble precision
	c.lt.d 		$f20, $f6		# Si no es $f20 < $f6
	bc1f 		error			# salto a error


    li.d $f22, 1.0 				# e
    li.d $f24, 1.0 				# fact
    li.d $f26, 1.0 				# numterminos
    li.d $f28, 1.0 				# ultimo_termino

# Fin del do
# } while {
# Comienzo del while

while:
	li.d		$f8, 1.0
    mul.d 		$f24, $f24, $f26      # fact *= numterminos;
    div.d 		$f28, $f8, $f24       # ultimo_termino = 1.0 / fact;
    add.d 		$f22, $f22, $f28      # e += ultimo_termino;
    add.d 		$f26, $f26, $f8       # ++numterminos;
	
	#while (ultimo_termino >= error)
	c.lt.d 		$f28, $f20		# Si $f28 < $f20
	bc1f 		while			# salto a whilw

	#std::cout <<  "\nNumero e: ";
	li 			$v0, 4			# $v0=4 funcion print string
	la 			$a0, cade		# $a0= direccion de la cadena a imprimir
	syscall

	# std::cout << std::fixed << std::setprecision(17) << e;
	li			$v0, 3			# $v0=3 funcion print double
    mov.d 		$f12, $f22		# $f12 = double a imprimir
    syscall

	# std::cout << "\nNumero de terminos: " << int(numterminos);
	li 			$v0, 4			# $v0=4 funcion print string
    la 			$a0, cadnt 		# $a0= direccion de la cadena a imprimir
    syscall

	li 			$v0, 3          # $v0=3 funcion print double
    mov.d 		$f12, $f26		# $f12 = double a imprimir
    syscall

	#  std::cout << "PR1: Fin del programa.\n";
    li 			$v0, 4			# $v0=4 funcion print string
    la 			$a0, cadfin		# $a0= direccion de la cadena a imprimir
    syscall

	# Exit 
	li 			$v0, 10  		# Salir del programa
	syscall