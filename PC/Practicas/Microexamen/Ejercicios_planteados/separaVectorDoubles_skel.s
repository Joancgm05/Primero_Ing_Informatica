# ME1: Separa Vector doubles
# Realizar un programa que trabaja con vectores número en punto flotante de
# doble precisión (double) mostrando que elementos son mayores que la media
# y cuales menores.

# Probar en https://codetest.iaas.ull.es/testeaprincipios/testea/831320bebaa0281d2ec84ef42594bd8e

	.data
nOptions = 3
sizeD = 8

str_mayor_igual_que: .asciiz " es mayor o igual"
str_menor_que:       .asciiz " es menor"
str_quelamedia:      .asciiz " que la media\n"

str_titulo:         .asciiz "\nSepara Elementos Según Media de Vector de Doubles\n"
str_elige:           .asciiz "\nElige vector de trabajo (1, 2, 3) o 0 para terminar: "
str_incorrecta:      .asciiz "Opción incorrecta"
str_termina:         .asciiz "\nTermina el programa\n"
v1:      .double -3.18, 8.8, 7.73, -0.71, -5.26, -3.89, -3.32, -0.39, 0.15, 0.98
v1Largo: .word 10
v2:      .double -1.06, 5.65, 2.96, -1.64, -2.92, -0.36
v2Largo: .word 6
v3:      .double -133.12
v3Largo: .word 0

	.text
# ↓↓↓↓ Debes codificar a partir de aquí ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

# double media(double* vect, int n) {
#   double acumulado = 0.0;
#   for(int i = 0; i < n; i++) {
#     acumulado = acumulado + vect[i];
#   }
#   double mediaAritmetica = acumulado / n;
#   return mediaAritmetica;
# }

# void separa(double* v, int largo) {
#   double mediaVector = media(v, largo);
#   for(int i = 0; i < largo; i++) {
#     double valor = v[i];
#     std::cout << valor;
#     if (valor >= mediaVector) {
#       std::cout << " es mayor o igual";
#     } else {
#       std::cout << " es menor";
#     }
#     std::cout << " que la media\n";
#   }
# }

#  ↑↑↑↑↑ Debes codificar hasta aquí ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
# int main() {
main:
    # Imprimir mensaje de bienvenida
    la $a0, str_titulo
    li $v0, 4
    syscall

    # Bucle principal
main_loop:
    # Solicitar al usuario que elija un vector
    la $a0, str_elige
    li $v0, 4
    syscall

    # Leer la opción del usuario
    li $v0, 5
    syscall
    move $t0, $v0       # Guardar la elección en $t0

    # Chequear si se debe terminar
    beqz $t0, exit      # Si $t0 es 0, terminar

    # Verificar la validez de la elección
    bltz $t0, error_option
    ble $t0, nOptions, non_error_option

error_option:
    # Manejar elección inválida
    la $a0, str_incorrecta
    li $v0, 4
    syscall
    j main_loop

non_error_option:
    # Asignar el vector correspondiente y su tamaño
    lw $s2, v1Largo          # v1Largo
    la $s3, v1          # Dirección de v1
    bne $t0, 1, check_v2
    j process

check_v2:
    lw $s2, v2Largo           # v2Largo
    la $s3, v2          # Dirección de v2
    bne $t0, 2, check_v3
    j process

check_v3:
    lw $s2, v3Largo           # v3Largo
    la $s3, v3          # Dirección de v3

process:
# ↓↓↓↓ Debes codificar a partir de aquí ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
# vTrabajo → s3
# largoTrabajo → s2

#     separa(vTrabajo, largoTrabajo);

#  ↑↑↑↑↑ Debes codificar hasta aquí ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
    j main_loop
#   }
exit:
    # std::cout << "\nTermina el programa\n";
    li $v0,4
    la $a0,str_termina
    syscall
    # Salir del programa
    li $v0, 10
    syscall
#}
