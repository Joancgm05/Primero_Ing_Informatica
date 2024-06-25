# ME1: Potencia Vector doubles
# Realizar un programa que trabaja con vectores número en punto flotante
# de doble precisión (double) y permite elevar todos sus elementos a una
# determinada potencia entera.

# Probar en https://codetest.iaas.ull.es/testeaprincipios/testea/d86b187431e85739958d612bf5687104

	.text
# ↓↓↓↓ Debes codificar a partir de aquí ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
# double eleva(double x, int n) {
#   double pot = 1.0;
#   for(int i = 1; i <= n; i++) {
#     pot = pot * x;
#   }
#   return pot;
# }

# double potencia_vect(double* v, int largo, int expo) {
#   double acumulado = 0.0;
#   for(int i = 0; i < largo; i++) {
#     double valor = v[i];
#     double elevado = eleva(valor, expo);
#     v[i] = elevado;
#     acumulado += elevado;
#   }
#   return acumulado;
# }
#  ↑↑↑↑↑ Debes codificar hasta aquí ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

# void printvec(double *v, const int n) {
printvec: # imprime un vector de doubles por consola separados por espacio
        # v → $a0 direccion de memoria del vector
        # n → $a1 numero de elementos del vector
        bnez $a1,pv_nozero
            jr $ra
        pv_nozero:
            addi $sp,-12
            sw $ra,0($sp)
            sw $s0,4($sp)
            sw $s1,8($sp)
            move $s0,$a0
            move $s1,$a1
            l.d $f12,0($s0)
            li $v0,3
            syscall
            li $a0,32
            li $v0,11
            syscall
            add $a0,$s0,8
            add $a1,$s1,-1
            jal printvec
            lw $ra,0($sp)
            lw $s0,4($sp)
            lw $s1,8($sp)
            addi $sp,12
            jr $ra

# #######################################################################
	.data
#   int v1Largo = 10;
v1Largo:	.word	10
#   double v1[v1Largo] = {-3.18,  8.8 ,  7.73, -0.71, -5.26, -3.89, -3.32, -0.39,  0.15, 0.98};
v1:		.double	-3.18,  8.8 ,  7.73, -0.71, -5.26, -3.89, -3.32, -0.39,  0.15, 0.98
#   int v2Largo = 6;
v2Largo:	.word	6
#   double v2[v2Largo] = {-1.06,  5.65,  2.96, -1.64, -2.92, -0.36};
v2:		.double	-1.06,  5.65,  2.96, -1.64, -2.92, -0.36
#   int v3Largo = 0;
v3Largo:	.word	0
#   double v3[] = {};
v3:		.double	-113.34

# Cadenas del programa principal
str_titulo:	.asciiz	"\nPotencia Vectores Doubles\n"
str_elige:	.asciiz	"\nElige vector de trabajo (1, 2, 3) o 0 para terminar: "
str_incorrecta:	.asciiz	"Opción incorrecta"
str_introexpo:	.asciiz	"Introduce exponente: "
str_lasumaes:	.asciiz	"\nLa suma es "
str_positiva:	.asciiz	" positiva\n"
str_negativa0:	.asciiz	" negativa o 0\n"
str_termina:	.asciiz	"\nTermina el programa\n"

	.text
# int main() {
# opcion → s0
# vTrabajo → s1
# largoTrabajo → s2
# n → s3
main:
#   std::cout << "\nPotencia Vectores Doubles\n";
	li	$v0,4
	la	$a0,str_titulo
	syscall

#   while(true) {
while_true:
#     std::cout << "\nElige vector de trabajo (1, 2, 3) o 0 para terminar: ";
	li	$v0,4
	la	$a0,str_elige
	syscall

#     int opcion;
#     std::cin >> opcion;
	li	$v0,5
	syscall
	move	$s0,$v0
#     if (opcion == 0) {
#       break;
#     }
	beqz	$s0,while_true_fin

#     if ((opcion < 0) || (opcion > 3)) {
if_opcion_0_3:
	bltz	$s0,if_opcion_0_3_dentro
	ble	$s0,3,if_opcion_0_3_fin
if_opcion_0_3_dentro:
#       std::cout << "Opción incorrecta";
	li	$v0,4
	la	$a0,str_incorrecta
	syscall
#       continue;
	b	while_true
#     }
if_opcion_0_3_fin:

#     double* vTrabajo = v1;
	la	$s1,v1
#     int largoTrabajo = v1Largo;
	lw	$s2,v1Largo
#     if (opcion == 2) {
if_opcion2:
	bne	$s0,2,if_opcion2_fin
#       vTrabajo = v2;
	la	$s1,v2
#       largoTrabajo = v2Largo;
	lw	$s2,v2Largo
#     }
if_opcion2_fin:
#     if (opcion == 3) {
if_opcion3:
	bne	$s0,3,if_opcion3_fin
#       vTrabajo = v3;
	la	$s1,v3
#       largoTrabajo = v3Largo;
	lw	$s2,v3Largo
#     }
if_opcion3_fin:

#     std::cout << "Introduce exponente: ";
	li	$v0,4
	la	$a0,str_introexpo
	syscall
#     int n;
#     std::cin >> n;
	li	$v0,5
	syscall
	move	$s3,$v0

# ↓↓↓↓ Debes codificar a partir de aquí ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
# vTrabajo → s1
# largoTrabajo → s2
# n → s3

#     printvec(vTrabajo, largoTrabajo);
#     double suma = potencia_vect(vTrabajo, largoTrabajo, n);
#     std::cout << "\nLa suma es " << suma;
#     if (suma > 0) {
#       std::cout << " positiva\n";
#     } else {
#       std::cout << " negativa o 0\n";
#     }
#     printvec(vTrabajo, largoTrabajo);
#  ↑↑↑↑↑ Debes codificar hasta aquí ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

#   }
	b	while_true
while_true_fin:
#   std::cout << "\nTermina el programa";
	li	$v0,4
	la	$a0,str_termina
	syscall
# }

	li	$v0,10
	syscall
