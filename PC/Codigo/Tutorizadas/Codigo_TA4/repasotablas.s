#/* 
# * File:   repasotablas.cpp
# * Authores: Carlos y Alberto
# *
# * Descripción: El usuario introducira por teclado la tabla de multiplicar que
# * quiere repasar. Si introduce un 0 el programa finalizara. Si introduce un
# * numero mayor que 0 debera pregutar al usuario por todas las multiplicaciones
# * del numero introducido por lo numero del 1 al 10. Al final de cada tabla se
# * visualizara el porcentaje de aciertos.
# */
##include <iostream>

#int main(int argc, char** argv) {

#  std::cout << "Programa para repasar las tablas de multiplicar.\n";
#  int n; // numero del que quiero repasar la tabla
#  do {
#    std::cout<<"¿Qué tabla deseas repasar? Introduce un número (0 para salir): ";
#    std::cin >> n;
#    if (n == 0) break; // si introduce un 0 sale del bucle
#    int aciertos = 0; // incializamos el numero de aciertos
#    for (int i = 1; i <= 10; i++) {
#      std::cout << i << " x " << n << " ? ";
#      int resultado;
#      std::cin >> resultado;
#      if (resultado == (i * n)) {
#        aciertos++;
#      }
#    }
#    int porcentaje = aciertos * 10;
#    std::cout << "Tu porcenaje de aciertos es del " << porcentaje << "%\n";
#  } while (n != 0);
#  std::cout << "Termina el programa.\n";
#}

	.data
strTitulo:	.asciiz "Programa para repasar las tablas de multiplicar.\n"
strQueTabla:	.asciiz "¿Qué tabla deseas repasar? Introduce un número (0 para salir): "
strX:		.asciiz " x "
strInterroga:	.asciiz " ? "
strTuPorcen:	.asciiz "Tu porcenaje de aciertos es del "
strPorcent:	.asciiz "%\n"
strTermina:	.asciiz "Termina el programa.\n"

	.text
# Asignación de variablas a registros
# n 		-> $s0
# aciertos 	-> $s1
# i 		-> $s2
# resultado 	-> $s3
# porcentaje	-> $s4

#int main(int argc, char** argv) {
main:

#  std::cout << "Programa para repasar las tablas de multiplicar.\n";
	li	$v0,4
	la	$a0,strTitulo
	syscall
	
#  int n; // numero del que quiero repasar la tabla
#  do {
do_while:
#    std::cout<<"¿Qué tabla deseas repasar? Introduce un número (0 para salir): ";
	li	$v0,4
	la	$a0,strQueTabla
	syscall
#    std::cin >> n;
	li	$v0,5
	syscall
	move	$s0,$v0
	
#    if (n == 0) break; // si introduce un 0 sale del bucle
	beq	$s0,$zero,fin_do_while
	
#    int aciertos = 0; // incializamos el numero de aciertos
	move	$s1,$zero
	
#    for (int i = 1; i <= 10; i++) {
	li	$s2,1
for:
	bgt	$s2,10,for_fin
	
#      std::cout << i << " x " << n << " ? ";
	li	$v0,1
	move	$a0,$s2
	syscall
	
	li	$v0,4
	la	$a0,strX
	syscall
	
	li	$v0,1
	move	$a0,$s0
	syscall
	
	li	$v0,4
	la	$a0,strInterroga
	syscall
	
#      int resultado;
#      std::cin >> resultado;
	li	$v0,5
	syscall
	move	$s3,$v0
	
#      if (resultado == (i * n)) {
if_resultado:
	mul	$t0,$s2,$s0
	bne	$s3,$t0,if_resultado_fin
	
#        aciertos++;
	addi	$s1,1
#      }
if_resultado_fin:

#    }

	addi	$s2,1
	b	for
for_fin:

#    int porcentaje = aciertos * 10;
	mul	$s4,$s1,10
	
#    std::cout << "Tu porcenaje de aciertos es del " << porcentaje << "%\n";
	li	$v0,4
	la	$a0,strTuPorcen
	syscall
	
	li	$v0,1
	move	$a0,$s4
	syscall
	
	li	$v0,4
	la	$a0,strPorcent
	syscall

#  } while (n != 0);
	bne	$s0,$zero,do_while
fin_do_while:

#  std::cout << "Termina el programa.\n";
	li	$v0,4
	la	$a0,strTermina
	syscall
	
#}
	li	$v0,10
	syscall


