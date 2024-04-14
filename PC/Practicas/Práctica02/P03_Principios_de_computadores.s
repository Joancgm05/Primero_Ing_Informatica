#// Solución PR3 curso 23-24
#// Manejo de matrices con funciones
#
#
#typedef struct {
#  int nFil;
nFil = 0	# El desplazamiento al campo dentro de la estructura
#  int nCol;
nCol = 4	# El desplazamiento al campo dentro de la estructura
#  float elementos[];
elementos = 8	# El desplazamiento al campo dentro de la estructura
#} structMat;
#

sizeF = 4	# Numero de bytes de un float
LF = 10		# Caracter salto de línea
	.data
#structMat mat1 {
#  6,
#  6,
#  {
#    11.11, 12.12, 13.13, 14.14, 15.15, 16.16,
#    21.21, 22.22, 23.23, 24.24, 25.25, 26.26,
#    31.31, 32.32, 33.33, 34.34, 35.35, 36.36,
#    41.41, 42.42, 43.43, 44.44, 45.45, 46.46,
#    51.51, 52.52, 53.53, 54.54, 55.55, 56.56,
#    61.61, 62.62, 63.63, 64.64, 65.65, 66.66
#  }
#};
mat1:	.word	6
	.word	6
	.float	11.11, 12.12, 13.13, 14.14, 15.15, 16.16,
	.float	21.21, 22.22, 23.23, 24.24, 25.25, 26.26,
	.float	31.31, 32.32, 33.33, 34.34, 35.35, 36.36,
	.float	41.41, 42.42, 43.43, 44.44, 45.45, 46.46,
	.float	51.51, 52.52, 53.53, 54.54, 55.55, 56.56,
	.float	61.61, 62.62, 63.63, 64.64, 65.65, 66.66

#structMat mat2 {
#  7,
#  10,
#  {
#    -36.886, -58.201,  78.671,  19.092, -50.781,  33.961, -59.511, 12.347,  57.306,  -1.938,
#    -86.858, -81.852,  54.623, -22.574,  88.217,  64.374,  52.312, 47.918, -83.549,  19.041,
#     4.255, -36.842,  82.526,  27.394,  56.527,  39.448,  18.429, 97.057,  76.933,  14.583,
#    67.79 ,  -9.861, -96.191,  32.369, -18.494, -43.392,  39.857, 80.686, -36.87 , -17.786,
#    30.073,  89.938,  -6.889,  64.601, -85.018,  70.559, -48.853, -62.627, -60.147,  -5.524,
#    84.323, -51.718,  93.127, -10.757,  32.119,  98.214,  69.471, 73.814,   3.724,  57.208,
#    -41.528, -17.458, -64.226, -71.297, -98.745,   7.095, -79.112, 33.819,  63.531, -96.181
#  }
#};
mat2:	.word	7
	.word	10
	.float	-36.886, -58.201,  78.671,  19.092, -50.781,  33.961, -59.511, 12.347,  57.306,  -1.938,
	.float	-86.858, -81.852,  54.623, -22.574,  88.217,  64.374,  52.312, 47.918, -83.549,  19.041,
	.float	4.255, -36.842,  82.526,  27.394,  56.527,  39.448,  18.429, 97.057,  76.933,  14.583,
	.float	67.79 ,  -9.861, -96.191,  32.369, -18.494, -43.392,  39.857, 80.686, -36.87 , -17.786,
	.float	30.073,  89.938,  -6.889,  64.601, -85.018,  70.559, -48.853, -62.627, -60.147,  -5.524,
	.float	84.323, -51.718,  93.127, -10.757,  32.119,  98.214,  69.471, 73.814,   3.724,  57.208,
	.float	-41.528, -17.458, -64.226, -71.297, -98.745,   7.095, -79.112, 33.819,  63.531, -96.181

# structMat mat3 {
#   1,
#   8,
#   {
#     -36.52,  35.3 ,  79.05, -58.69, -55.23, -19.44, -88.63, -93.61
#   }
# };
mat3:	.word	1
	.word	8
	.float	-36.52,  35.3 ,  79.05, -58.69, -55.23, -19.44, -88.63, -93.61

# structMat mat4 {
#   16,
#   1,
#   { -90.57, -65.11, -58.21, -73.23, -89.38, -79.25,  16.82,  66.3 ,
#     -96.14, -97.16, -24.66,   5.27, -33.5 , -13.09,  27.13, -74.83 }
# };
mat4:	.word	16
	.word	1
	.float	-90.57, -65.11, -58.21, -73.23, -89.38, -79.25,  16.82,  66.3
	.float	-96.14, -97.16, -24.66,   5.27, -33.5 , -13.09,  27.13, -74.83

# structMat mat5 {
#   1,
#   1,
#   { 78.98 }
# };
mat5:	.word	1
	.word	1
	.float	78.98

# structMat mat6 {
#   0,
#   0,
#   { 0 }
# };
mat6:	.word	0
	.word	0
	.float	0.0

#float infinito = INFINITY;
infinito:	.word	0x7F800000

# Cadenas de caracteres
str_titulo:	.asciiz	"\nComienza programa manejo matrices con funciones\n"
str_menu:	.ascii	"(0) Terminar el programa\n"
		.ascii	"(1) Cambiar la matriz de trabajo\n"
		.ascii	"(3) Cambiar el valor de un elemento\n"
		.ascii	"(4) Intercambiar un elemento con su opuesto\n"
		.ascii	"(7) Encontrar el minimo\n"
		.asciiz	"\nIntroduce opción elegida: "
str_errorOpc:	.asciiz	"Error: opcion incorrecta\n"
str_termina:	.asciiz	"\nTermina el programa\n"
str_elijeMat:	.asciiz	"\nElije la matriz de trabajo (1..6): "
str_numMatMal:	.asciiz	"Numero de matriz de trabajo incorrecto\n"
str_errorFil:	.asciiz	"Error: dimension incorrecta.  Numero de fila incorrecto\n"
str_errorCol:	.asciiz	"Error: dimension incorrecta.  Numero de columna incorrecto\n"
str_indFila:	.asciiz	"\nIndice de fila: "
str_indCol:	.asciiz	"Indice de columna: "
str_nuevoValor:	.asciiz	"Nuevo valor para el elemento: "
str_valMin:	.asciiz	"\nEl valor minimo esta en ("
str_conValor:	.asciiz	") con valor "

str_matTiene:	.asciiz	"\n\nLa matriz tiene dimension "

option_0 = 0
option_1 = 1
option_2 = 2
option_3 = 3
option_4 = 4
option_5 = 5
option_6 = 6
option_7 = 7

	.text

# subrutinas

# Subrutina PRINT MAT
# $s0 = dirección de inicio de la matriz
# $s1 = número de filas
# $s2 = número de columnas
# $s3 = dirección de la matriz

print_mat:
	# Función para imprimir una matriz por consola
	# PUSH
	addi $sp, $sp, -32
	sw 		$s0, 0($sp)  
	sw 		$s1, 4($sp)  
	sw 		$s2, 8($sp)  
	sw 		$s3, 12($sp) 
	sw 		$s4, 16($sp) 
	sw 		$s5, 20($sp)  
	sw 		$s6, 24($sp) 
	sw 		$ra, 28($sp)

	move $s3, $a1
	la 		$s0, 8($s3) # Primer elemento de la matriz
	lw 		$s1, 0($s3) # Número de filas
	lw 		$s2, 4($s3) # Número de columnas

	# std::cout << "\n\nLa matriz tiene dimension " << nFil << 'x' << nCol << '\n';
	# std::cout << "\n\nLa matriz tiene dimension "
	li 		$v0, 4
	la 		$a0, str_matTiene
	syscall
	# << nFil
	move 	$a0, $s1
	li 		$v0, 1
	syscall
	# << "x"
	li 		$a0, 120
	li 		$v0, 11
	syscall
	# << nCol
	move 	$a0, $s2
	li 		$v0, 1
	syscall
	# << '|n'
	li 		$a0, 10
	li 		$v0, 11
	syscall

	mul 	$s4, $s1, $s2 # Se almacena en $s4 el tamaño de la matriz
	beqz 	$s4, next_instruction # Si el tamaño de la matriz es cero se salta a la siguiente instrucción
	move 	$s5, $zero # Se inicializa el índice de filas a 0
	move 	$s6, $zero # Se inicializa el índice de columnas a 0

# for(int f = 0; f < nFil; f++) {
for_print_mat:
	l.s 	$f4, 0($s0) # Cargo en f4 el flotante que se encuentra en $s0
	
	# std::cout << elem[f*nCol + c] << ' ';
	# std::cout << elem[f*nCol + c]
	li 		$v0, 2
	mov.s 	$f12, $f4
	# std::cout << " "
	syscall
	li 		$v0, 11
	li 		$a0, 32
	syscall


	addi  	$s0, $s0, sizeF # Se almacena el tamaño de un flotante (4)
	addi 	$s5, $s5, 1 # Se añade 1 al índice de filas
	addi 	$s6, $s6, 1 # Se añade 1 al índice de columnas
	bne		$s6, $s2, print_line_jump # Si el índice y el número de columnas es igual se hace un salto de línea
	move  	$s6, $zero # Se inicializa el índice de columnas a 0
	
	# std::cout << '\n';
	li		$v0, 11
	li 		$a0, 10
	syscall

print_line_jump:

	blt 	$s5, $s4, for_print_mat # Si el índice de filas no ha llegado al número total de elementos de la matriz salta al for
	
	# std::cout << '\n';
	li 		$v0, 11
	li 		$a0, 10
	syscall

next_instruction:

	#POP
	lw 		$s0, 0($sp)
	lw		$s1, 4($sp)
	lw		$s2, 8($sp)
	lw		$s3, 12($sp)
	lw		$s4, 16($sp)
	lw		$s5, 20($sp)
	lw		$s6, 24($sp)
	lw		$ra, 28($sp)
	addi	$sp, $sp, 32
	jr 		$ra

print_mat_fin:

# subrutina CHANGE ELEMENT 

# $a1 = Dirección de la matriz
# $a2 = Filas del elemento
# $a3 = Columnas del elemento
# $f2 = Flotante

change_elto:

	la 		$t0, 8($a1) # Se carga en $t0 el primer elemento de la matriz
	lw 		$t1, 4($a1) # Numero de columnas

	mul 	$t2, $a2, $t1 # [indF * numCOl
	addu	$t2, $t2, $a3 # [indF * numCol + indC]
	mul 	$t2, $t2, sizeF # Se le multiplica el tamaño del flotante ($t2 * 4)
	addu 	$t2, $t2, $t0 # Se carga la dirección en $t2

	s.s 	$f12, 0($t2) # Almaceno la dirección del flotante seleccionado
	jr		$ra

change_elto_fin:

# subrutina SWAP
# $a0 Se almacena la dirección del primer elemento
# $a3 Se almacena la dirección del segundo elemento

swap:

	l.s 	$f4, 0($a0) # float temp1 = *e1;
	l.s 	$f5, 0($a3) # float temp2 = *e2;
	s.s 	$f5, 0($a0) # *e1 = temp2;
	s.s 	$f4. 0($a3) # *e2 = temp1;
	jr 		$ra

swap_fin:

#subrutina INTERCAMBIA
# $a1 Almacena la dirección de la matriz
# $a2 ALmacena las filas del elmento
# $a3 Almacena las filas del elmento

intercambia:

	la 		$t0, 8($a1) # Se carga en $t0 el primer elemento de la matriz
	lw		$t1, 0($a1) # Se carga en $t1 el número de filas
	lw 		$t2, 4($a1) # Se carga en $t2 el número de columnas
	#float* e1 = &datos[indF * numCol + indC];
	mul 	$t5, $a2, $t2 # [indF * numCol
	addu 	$t5, $t5, $a3 # [indF * numCol + indC]
	mul 	$t5, $t5, sizeF # Se le multiplica el tamaño del flotante (4)
	addu 	$t3, $t0, $t5 # Almacena la nueva dirección
	move 	$a0, $t3
	
	#float* e2 = &datos[(numFil - indF - 1) * numCol + (numCol - indC - 1)];
	sub 	$t8, $t1, $a2 # numFil - indF
	li 		$t7, 1
	sub 	$t8, $t8, $t7 # [(numFil - indF - 1)
	mul 	$t8, $t8, $t2 # [(numFil - indF - 1) * numCol
	sub		$t4, $t2, $a3 # (numCol - indC
	sub 	$t4, $t4, $t7 # (numCol - indC - 1)]
	addu 	$t8, $t8, $t4 # [(numFil - indF - 1) * numCol + (numCol - indC - 1)]
	mul 	$t8, $t8, sizeF # Se multiplica por el tamaño del flotante (4)
	addu 	$t8, $t8, $t0 # Se almacena la dirección
	move 	$a3, $t8
	
	# Pila para almacenar la dirección (PUSH)
	addi 	$sp, $sp, -4 
	sw 		$ra, 0($sp)

	# Vuelvo a llamar a la función
	jal 	swap 

	# Recupero la dirección almacenada en la pila (POP)
	lw 		$ra, 0($sp)
	addi 	$sp, $sp, 4

	jr 		$ra

intercambia_fin:

# subrutina FIND-MIN

find_min:
	la 		$t0, 8($a1) # Se carga en $t0 el primer elemento de la matriz
	lw 		$t1, 0($a1) # Se carga en $t1 el número de filas
	lw 		$t2, 4($a1) # Se carga en $t2 el número de columnas
	
	move 	$t4, $zero # Cargo el índice de filas a 0
	
	l.s 	$f4, infinito #float min = infinito;
	li 		$t6, -1 # int fmin = -1;
	li 		$t7, -1 # int cmin = -1;

	mul 	$t8, $t1, $t2 # Se obtiene el tamaño de la matriz
	beqz 	$t8, find_out

# for(int f = 0; f < nFil; f++) {
for_find_min_one: 
	move 	$t5, $zero # inicializo el índice de columnas a 0
	mul		 $t8, $t4, $t2 #$t8 = i*ncol
# for(int c = 0; c < numCol; c++) {
for_find_min_two:
	addu	 $t9, $t8, $t5 # $t9 = i*ncol + j
	mul 	 $t9, $t9, sizeF #$t9 = $t9 * 4
	addu	 $t9, $t9, $t0 
	
	#float valor = datos[f * numCol + c];
	l.s		 $f5, 0($t9) #asigno el valor de ese punto
	#if (valor < min) {
	c.lt.s 	$f5, $f4
	bc1f 	find_jump
	mov.s 	$f4, $f5 #min = valor;
	move 	$t6, $t4 #fmin = f;
	move 	$t7, $t5 #cmin = c;

find_jump:
	addi 	$t5, $t5, 1 # Se le suma 1 al índice de columnas
	blt 	$t5, $t2, for_find_min_two # Si el índice de columnas es menor que el número de columnas se salta el segundo buble

	addi 	$t4, $t4, 1 # Se le suma 1 al índice de filas 
	blt 	$t4, $t1, for_find_min_one # Si el índice de filas es menor que el número de filas se salta al primer blucle

find_out:

	mov.s 	$f0, $f4 # Se carga en $f0 el contenido de $f4
	move 	$v0, $t6 # Se carga en $v0 el contenido de $t6
	move 	$v1, $t7 # Se carga en $v1 el contenido de $t7 

	jr 		$ra

find_min_end:

# MAIN
# $s0 = se almacena la opción elegida
# $s1 = Se almacena la matriz elegida
# $s7 = Se almacena la dirección de la matriz elegida

main:

	#std::cout << "\nComienza programa manejo matrices con funciones\n";
	li 		$v0, 4
	la 		$a0, str_titulo
	syscall
	#structMat* matTrabajo = &mat1;
	la 		$s7, mat1
while:

	#print_mat(matTrabajo);
	move 	$a1, $s7
	jal	 	print_mat

	# std::cout <<  "(0) Terminar el programa\n"
	# "(1) Cambiar la matriz de trabajo\n"
  	# "(3) Cambiar el valor de un elemento\n"
 	# "(4) Intercambiar un elemento con su opuesto\n"
 	# "(7) Encontrar el minimo\n"
  	# "\nIntroduce opción elegida: ";
	li 		$v0, 4
	la 		$a0, str_menu
	syscall

	li 		$v0, 5
	syscall
	move $s0, $v0
	beq $s0, option_0, termina_programa
	beq $s0, option_1, change_mat
	beq $s0, option_2, ordenacion_burbuja
	beq $s0, option_3, change_element_value
	beq $s0, option_4, change_element_value
	beq $s0, option_7, find_min	
	# std::cout << "Numero de matriz de trabajo incorrecto\n";
	li 		$v0, 4
	la 		$a0, str_errorOpc
	syscall
	
	j 		while

while_end:

# $s1 --> almacenamos la matriz escogida
change_mat:
	# std::cout << "\nElije la matriz de trabajo (1..6): ";
	li 		$v0, 4
	la 		$a0, str_elijeMat
	syscall

	li 		$v0, 5
	syscall
	move 	$s1, $v0 

	beq 	$s1, option_1, change1 # if (matT == 1) {
	beq 	$s1, option_2, change2 # if (matT == 2) {
	beq 	$s1, option_3, change3 # if (matT == 3) {
	beq 	$s1, option_4, change4 # if (matT == 4) {
	beq 	$s1, option_5, change5 # if (matT == 5) {
	beq 	$s1, option_6, change6 # if (matT == 6) {

	# std::cout << "Numero de matriz de trabajo incorrecto\n";
	# continue;  // volvemos al principio del bucle
incorrecto:
	li 		$v0, 4
	la 		$a0, str_numMatMal
	syscall
	j 		while

	# matTrabajo = &mat1;
	# continue; 
change1:
	la 		$s7, mat1
	j 		while

	# matTrabajo = &mat2;
	# continue; 
change2:
	la 		$s7, mat2
	j 		while

	# matTrabajo = &mat3;
	# continue; 
change3:
	la 		$s7, mat3
	j 		while

	# matTrabajo = &mat4;
	# continue; 
change4:
	la 		$s7, mat4
	j 		while

	# matTrabajo = &mat5;
	# continue; 
change5:
	la 		$s7, mat5
	j 		while

	# matTrabajo = &mat6;
	# continue; 
change6:
	la 		$s7, mat6
	j 		while


change_mat_end: 

# $a1 Almacena la dirección de la matriz
# $a2 Almacena la fila del elemento
# $a3 Almacena la columna del elemento
# $f12 Almacena un flotante
# $s2 Almacena las filas
# $s3 Almacena las columnas
# $s4 Almacena el índice de la fila
# s5 Almacena el índice de la columna
change_element_value:
	
	lw 		$s2, 0($s7)  # Se almacena nFil
	lw 		$s3, 4($s7)	# Se almacena nCol
	#std::cout << "\nIndice de fila: ";
	li 		$v0, 4
	la 		$a0, str_indFila
	syscall
	#std::cin >> indFil;
	li 		$v0, 5
	syscall
	move 	$s4, $v0
	#if ((indFil < 0) || (indFil >= matTrabajo->nFil)) {
	slt 	$t0, $s4, $zero
	sge 	$t1, $s4, $s2
	or 		$t0, $t0, $t1
	bnez 	$t0, fil_error
	#std::cout << "Indice de columna: ";
	li 		$v0, 4
	la 		$a0, str_indCol
	syscall
	#std::cin >> indCol;
	li 		$v0, 5
	syscall
	move 	$s5, $v0
	#if ((indCol < 0) || (indCol >= matTrabajo->nCol)){
	slt 	$t0, $s5, $zero
	sge 	$t1, $s5, $s3
	or 		$t0, $t0, $t1
	bnez 	$t0, col_error

	beq 	$s0, option_3, change_value

	move 	$a1, $s7
	move	$a2, $s4
	move	$a3, $s5
	jal 	intercambia
	j 		while

change_value:
	#std::cout << "Nuevo valor para el elemento: ";
	li 		$v0, 4
	la 		$a0, str_nuevoValor
	syscall
	#std::cin >> valor;
	li 		$v0, 6
	syscall

	#change_elto(matTrabajo, indFil, indCol, valor);
	mov.s 	$f12, $f0 
	move 	$a1, $s7 
	move 	$a2, $s4
	move 	$a3, $s5
	jal 	change_elto
	j 		while
	change_value_end:
	

# std::cerr << "Error: dimension incorrecta.  Numero de fila incorrecto\n";
fil_error:
	li 		$v0, 4
	la 		$a0, str_errorFil
	syscall
	#continue;
	j		 while
#  std::cerr << "Error: dimension incorrecta.  Numero de columna incorrecto\n";
col_error:
	li 		$v0, 4
	la 		$a0, str_errorCol
	syscall
	#continue;
	j 		while

change_element_value_fin:

# $s0 --> índice fila mínimo
# $s1 --> índice columna mínimo
# $f20 --> valor flotante mínimo
encontrar_minimo:
	move 	$a1, $s7
	#std::tie(valorMin, filaMin, columnaMin) = find_min(matTrabajo);
	jal 	encontrar_minimo
	move 	$s0, $v0 
	move 	$s1, $v1
	mov.s 	$f20, $f0
	#std::cout << "\nEl valor minimo esta en (" << filaMin << ','
	li 		$v0, 4
	la 		$a0, str_valMin
	syscall
	li 		$v0, 1
	move 	$a0, $s0
	syscall
	# << ','
	li 		$a0, 44
	li 		$v0, 11
	syscall
	#<< columnaMin <<") con valor " << valorMin;
	li 		$v0, 1
	move 	$a0, $s1
	syscall
	li 		$v0, 4
	la 		$a0, str_conValor
	syscall
	mov.s 	$f12, $f20
	li 		$v0, 2
	syscall
	j 		while
encontrar_minimo_fin:

# MODIFICACIÓN-PRUEBA
# $s2 --> filas
# $s3 --> columnas
# $s4 --> índice fila
# $s7 --> dirección de la matriz
ordenacion_burbuja:
	
	lw 		$s2, 0($s7) #filas
	#std::cout << "\nIndice de fila: ";
	li 		$v0, 4
	la 		$a0, str_indFila
	syscall
	#std::cin >> indFil;
	li 		$v0, 5
	syscall
	move 	$s4, $v0
	#if ((indFil < 0) || (indFil >= matTrabajo->nFil)) {
	slt 	$t0, $s4, $zero
	sge 	$t1, $s4, $s2
	or 		$t0, $t0, $t1
	bnez 	$t0, fil_error
	move 	$a0, $s7 #dirección
	move 	$a2, $s4 #índice fila

	jal 	sort_row
	j 		while

ordenacion_burbuja_fin:

sort_row:
		
	la 		$t0, 8($a0) # Se carga en $t0 el primer elemento de la matriz
	lw 		$t1, 0($a0) # Se carga en $t1 el número de filas
	lw 		$t2, 4($a0) # Se carga en $t2 el número de columnas
	
	addi	$t3, $t2, -1 # Se almacena en $t3 el número de columnas - 1
	move 	$t9, $a2 # Se almacena el índice de la fila en $t9

	mul 	$t8, $t1,$t2 # Se obtiene el tamaño de la matriz
	beqz 	$t8, sort_row_out # Si el tamaño de la matriz es cero se salta a la siguiente instrucción

	move 	$t4, $zero # inicializo el índice de filas a 0 (i)

# for(int f = 0; f < nFil; f++) {
for_sort_one: 
	move 	$t5, $zero # inicializo el índice de columnas a 0 
	

for_sort_two:
	#hallo la posición del primer elemento
	mul 	$t7, $a2, $t2 #nCol * índFila
	add 	$t7, $t7, $t5 #nCol * indFila + j
	mul 	$t7, $t7, sizeF
	addu 	$t7, $t7, $t0
	l.s 	$f4, 0($t7)
	#hallo el del segundo
	mul 	$t8, $t9, $t2
	add 	$t8, $t8, $t5
	addi 	$t8, $t8, 1
	mul 	$t8, $t8, sizeF
	addu 	$t8, $t8, $t0
	l.s 	$f5, 0($t8)
	#comparo el valor de los dos
	c.le.s 	$f4, $f5
	bc1t 	sort_jump # si no se cumple que sea mayor se salta el if
	move 	$a0, $t7
	move 	$a3, $t8
	
	addi 	$sp, $sp, -4
	sw 		$ra, 0($sp)
	jal 	swap
	lw 		$ra, 0($sp)
	addi 	$sp, $sp, 4

sort_jump:
	
	sub 	$t6, $t3, $t4 #nCol - 1 - i
	addi 	$t5, $t5, 1 # j++
	blt 	$t5, $t6, for_sort_two

	addi 	$t4, $t4, 1 # i++
	blt 	$t4, $t3, for_sort_one


sort_row_out:

	jr 		$ra
sort_row_end:

termina_programa:
	# std::cout << "\nTermina el programa\n"
	li 		$v0, 4
	la 		$a0, str_termina
	syscall
	
	li		 $v0, 10
	syscall
