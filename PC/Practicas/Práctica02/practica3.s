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
opc_0 = 0
opc_1 = 1
opc_2 = 2
opc_3 = 3
opc_4 = 4
opc_5 = 5
opc_6 = 6
opc_7 = 7

sizeF = 4	# Numero de bytes de un float
LF = 10
space = 32
x = 120
# Caracter salto de línea
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
		.ascii	"(2) Ordenar una fila\n"
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

	.text


# SUBRUTINAS

# PRINT MAT

# $s0 --> dirección elementos de mat
# $s1 --> filas
# $s2 --> columnas
# $s3 --> dirección de la matriz
print_mat:
	addi $sp, $sp, -32
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
	sw $s4, 16($sp)
	sw $s5, 20($sp)
	sw $s6, 24($sp)
	sw $ra, 28($sp)
	
	move $s3, $a1
	la $s0, 8($s3) #Primer elemento
	lw $s1, 0($s3) #nFil
	lw $s2, 4($s3) #nColum

	# std::cout << "\n\nLa matriz tiene dimension "
	li $v0, 4
	la $a0, str_matTiene
	syscall
	
	

	# << nFil
	move $a0, $s1
	li $v0, 1
	syscall

	# << 'x'
	li $a0, 120
	li $v0, 11
	syscall

	# << nCol
	move $a0, $s2
	li $v0, 1
	syscall

	# << '\n'
	li $a0, 10
	li $v0, 11
	syscall

	
	mul $s4, $s1, $s2 # tamaño total de la matriz ($s5)
	beqz $s4, vuelta_a_codigo
	move $s5, $zero # inicializo el índice de filas a 0
	li $s6, 0 # inicializo el índice de columnas a 0

# for(int f = 0; f < nFil; f++) {
for_print: 
		l.s $f4, 0($s0) # cargo en f4 el flotante que se encuentra en esta posición
  	
		# std::cout << elem[f*nCol + c] << ' ';
		li $v0, 2
		mov.s $f12, $f4
		syscall
		
		li $v0, 11
		li $a0, 32
		syscall

		# aumento el índice y comparo para el salto, además, avanzo en la dirección
		addi $s0, $s0, sizeF
		addi $s5, $s5, 1 # aumento índice fila
		addi $s6, $s6, 1 # aumento el índice de la columna, para cuando llegue al final inserte salto de línea
		bne $s6, $s2, salto_print
		move $s6, $zero # lo vuelvo a inicializar a 0
		# std::cout << '\n';
		li $v0, 11
		li $a0, 10
		syscall

salto_print:	blt $s5, $s4, for_print		# si el índice no ha llegado al nº total de elementos salta a for
		
		# std::cout << '\n';
		li $v0, 11
		li $a0, 10
		syscall

vuelta_a_codigo:

		lw $s0, 0($sp)
		lw $s1, 4($sp)
		lw $s2, 8($sp)
		lw $s3, 12($sp)
		lw $s4, 16($sp)
		lw $s5, 20($sp)
		lw $s6, 24($sp)
		lw $ra, 28($sp)
		addi $sp, $sp, 32
		jr $ra

print_mat_fin:



# CHANGE ELEMENT

# $a1 --> dirección de la matriz
# $a2 --> fila del elemento
# $a3 --> columna del elemento
# $f12 --> nuevo flotante
change_elto:
	la $t0, 8($a1) #primer elemento de la matriz
	lw $t1, 4($a1) #nColumna

	#mat->elementos[indF * numCol + indC] = valor;
	mul $t2, $a2, $t1 #[indF * numCol
	addu $t2, $t2, $a3 #indF * numCol + indC
	mul $t2, $t2, sizeF #$t2 * 4
	addu $t2, $t2, $t0 #hallo la dir.

	s.s $f12, 0($t2) #cargo en la dirección el flotante que he introducido
	jr $ra
change_elto_fin:


# SWAP
# $a0, dirección del primer elemento
# $a3, dirección del segundo elemento
swap:
	#float temp1 = *e1;
	l.s $f4, 0($a0)
	#float temp2 = *e2;
	l.s $f5, 0($a3)
	#*e1 = temp2;
	s.s $f5, 0($a0)
	#*e2 = temp1;
	s.s $f4, 0($a3)
	
	jr $ra
swap_fin:


#INTERCAMBIA
# $a1 --> dirección de la matriz
# $a2 --> fila del elemento
# $a3 --> columna del elemento
intercambia:
	la $t0, 8($a1) #primer elemento matriz
	lw $t1, 0($a1) #nFila
	lw $t2, 4($a1) #nColumnas
	
	#float* e1 = &datos[indF * numCol + indC];
	mul $t5, $a2, $t2
	
	addu $t5, $t5, $a3
	
	mul $t5, $t5, sizeF
	
	addu $t3, $t0, $t5 #para hallar la nueva dirección

	move $a0, $t3 

	#float* e2 = &datos[(numFil - indF - 1) * numCol + (numCol - indC - 1)];
	sub $t8, $t1, $a2 # numFil - indF

	li $t7, 1
	sub $t8, $t8, $t7 # (numFil - indF - 1)


	mul $t8, $t8, $t2 # (numFil - indF - 1) * numCol


	sub $t4, $t2, $a3 # numCol - indC


	sub $t4, $t4, $t7 # numCol - indC - 1


	addu $t8, $t8, $t4 # (numFil - indF - 1) * numCol + (numCol - indC - 1)]


	mul $t8, $t8, sizeF
	
	addu $t8, $t8, $t0
	
	move $a3, $t8
	#antes de saltar uso la pila para almacenar la dirección a la que tengo que volver
	addi $sp, $sp, -4
	sw $ra, 0($sp)

	jal swap #llamo a la función swap

	#recupero la dirección a la que tengo que saltar y vacío la pila
	lw $ra, 0($sp)
	addi $sp, $sp, 4

	jr $ra
intercambia_fin:



# FIND-MIN
find_min:
	la $t0, 8($a1) #primer elemento matriz
	lw $t1, 0($a1) #nFila
	lw $t2, 4($a1) #nColumnas
	
	move $t4, $zero # inicializo el índice de filas a 0
	
	#float min = infinito;
	l.s $f4, infinito
	# int fmin = -1;
	li $t6, -1
	# int cmin = -1;
	li $t7, -1

	mul $t8, $t1,$t2
	beqz $t8, salir_find
# for(int f = 0; f < nFil; f++) {
for_find: 
	move $t5, $zero # inicializo el índice de columnas a 0
	mul $t8, $t4, $t2 #$t8 = i*ncol
# for(int c = 0; c < numCol; c++) {
segundo_for:
	addu $t9, $t8, $t5 # $t9 = i*ncol + j
	mul $t9, $t9, sizeF #$t9 = $t9 * 4
	addu $t9, $t9, $t0 #desplazo la dirección
	
	#float valor = datos[f * numCol + c];
	l.s $f5, 0($t9) #asigno el valor de ese punto
	#if (valor < min) {
	c.lt.s $f5, $f4
	bc1f salto_find
	#min = valor;
	mov.s $f4, $f5
	#fmin = f;
	move $t6, $t4
	#cmin = c;
	move $t7, $t5

salto_find:
	addi $t5, $t5, 1
	blt $t5, $t2, segundo_for

addi $t4, $t4, 1
blt $t4, $t1, for_find

salir_find:
#ahora asigno el valor a los registros de retorno
mov.s $f0, $f4
move $v0, $t6
move $v1, $t7

jr $ra

find_min_fin:


# PROGRAMA MAIN
# $s0 --> opción escogida
# $s1 --> almacenamos la matriz escogida (cambiar matriz)
# $s7 --> dirección de la matriz
main: 
	#std::cout << "\nComienza programa manejo matrices con funciones\n";
	li $v0, 4
	la $a0, str_titulo
	syscall

	#structMat* matTrabajo = &mat1;
	la $s7, mat1
	#cargo el número de filas y columnas en estos salvados para usarlo en la parte de cambiar matriz y cambiar_intercambiar_valor

while:
	
	#print_mat(matTrabajo);
	move $a1, $s7
	jal print_mat
	

	# std::cout <<  "(0) Terminar el programa\n"
	# "(1) Cambiar la matriz de trabajo\n"
  # "(3) Cambiar el valor de un elemento\n"
  # "(4) Intercambiar un elemento con su opuesto\n"
  # "(7) Encontrar el minimo\n"
  # "\nIntroduce opción elegida: ";
	li $v0, 4
	la $a0, str_menu
	syscall

	li $v0, 5
	syscall
	move $s0, $v0
	beq $s0, opc_0, termina_programa
	beq $s0, opc_1, cambiar_matriz
	beq $s0, opc_2, ordenacion_burbuja
	beq $s0, opc_3, cambiar_intercambiar_valor_elemento
	beq $s0, opc_4, cambiar_intercambiar_valor_elemento
	beq $s0, opc_7, encontrar_minimo
	
	# std::cout << "Numero de matriz de trabajo incorrecto\n";
	li $v0, 4
	la $a0, str_errorOpc
	syscall
	
	j while

while_fin:

# $s1 --> almacenamos la matriz escogida
cambiar_matriz:
		# std::cout << "\nElije la matriz de trabajo (1..6): ";
		li $v0, 4
		la $a0, str_elijeMat
		syscall

		li $v0, 5
		syscall
		move $s1, $v0 

		# if (matT == 1) {
		beq $s1, opc_1, cambiar1
		#if (matT == 2) {
		beq $s1, opc_2, cambiar2
		#if (matT == 3) {
		beq $s1, opc_3, cambiar3
		# if (matT == 4) {
		beq $s1, opc_4, cambiar4
		# if (matT == 5) {
		beq $s1, opc_5, cambiar5
		# if (matT == 6) {
		beq $s1, opc_6, cambiar6

			# std::cout << "Numero de matriz de trabajo incorrecto\n";
			# continue;  // volvemos al principio del bucle
			incorrecto:
				li $v0, 4
				la $a0, str_numMatMal
				syscall
				j while

			# matTrabajo = &mat1;
			# continue; 
			cambiar1:
					la $s7, mat1
					j while

			# matTrabajo = &mat2;
			# continue; 
			cambiar2:
					la $s7, mat2
					j while

			# matTrabajo = &mat3;
			# continue; 
			cambiar3:
					la $s7, mat3
					j while

			# matTrabajo = &mat4;
			# continue; 
			cambiar4:
					la $s7, mat4
					j while

			# matTrabajo = &mat5;
			# continue; 
			cambiar5:
					la $s7, mat5
					j while

			# matTrabajo = &mat6;
			# continue; 
			cambiar6:
					la $s7, mat6
					j while


cambiar_matriz_fin: 

# $a1 --> dirección de la matriz
# $a2 --> fila del elemento
# $a3 --> columna del elemento
# $f12 --> nuevo flotante
# $s2 --> filas
# $s3 --> columnas
# $s4 --> índice fila
# s5 --> índice columna
cambiar_intercambiar_valor_elemento:
	
	lw $s2, 0($s7)  #nFila
	lw $s3, 4($s7)	#nColumna
	
	#std::cout << "\nIndice de fila: ";
	li $v0, 4
	la $a0, str_indFila
	syscall
	
	#std::cin >> indFil;
	li $v0, 5
	syscall
	move $s4, $v0
	
	#if ((indFil < 0) || (indFil >= matTrabajo->nFil)) {
	slt $t0, $s4, $zero
	sge $t1, $s4, $s2
	or $t0, $t0, $t1
	bnez $t0, error_fila

	#std::cout << "Indice de columna: ";
	li $v0, 4
	la $a0, str_indCol
	syscall

	#std::cin >> indCol;
	li $v0, 5
	syscall
	move $s5, $v0

	#if ((indCol < 0) || (indCol >= matTrabajo->nCol)){
	slt $t0, $s5, $zero
	sge $t1, $s5, $s3
	or $t0, $t0, $t1
	bnez $t0, error_columna

	beq $s0, opc_3, cambiar_valor
	#si la opción escogida es 4 salta a la subrutina intercambia
	move $a1, $s7
	move $a2, $s4
	move $a3, $s5
	jal intercambia
	j while


	cambiar_valor:
	#std::cout << "Nuevo valor para el elemento: ";
	li $v0, 4
	la $a0, str_nuevoValor
	syscall

	#std::cin >> valor;
	li $v0, 6
	syscall
	

	#change_elto(matTrabajo, indFil, indCol, valor);
	mov.s $f12, $f0 #almaceno el valor en el registro f12 para pasarlo como argumento
	move $a1, $s7 # lo mismo con la dirección de la matriz y el resto de elementos
	move $a2, $s4
	move $a3, $s5
	jal change_elto
	j while
	cambiar_valor_fin:
	

# std::cerr << "Error: dimension incorrecta.  Numero de fila incorrecto\n";
error_fila:
	li 	$v0, 4
	la $a0, str_errorFil
	syscall
	#continue;
	j while
#  std::cerr << "Error: dimension incorrecta.  Numero de columna incorrecto\n";
error_columna:
	li 	$v0, 4
	la $a0, str_errorCol
	syscall
	#continue;
	j while

cambiar_intercambiar_valor_elemento_fin:

# $s0 --> índice fila mínimo
# $s1 --> índice columna mínimo
# $f20 --> valor flotante mínimo
encontrar_minimo:
	move $a1, $s7
	#std::tie(valorMin, filaMin, columnaMin) = find_min(matTrabajo);
	jal find_min
	move $s0, $v0 
	move $s1, $v1
	mov.s $f20, $f0
	
	#std::cout << "\nEl valor minimo esta en (" << filaMin << ','
	li $v0, 4
	la $a0, str_valMin
	syscall

	li $v0, 1
	move $a0, $s0
	syscall

	# << ','
	li $a0, 44
	li $v0, 11
	syscall
	
	#<< columnaMin <<") con valor " << valorMin;
	li $v0, 1
	move $a0, $s1
	syscall

	li $v0, 4
	la $a0, str_conValor
	syscall
	
	mov.s $f12, $f20
	li $v0, 2
	syscall

	j while
encontrar_minimo_fin:


# MODIFICACIÓN-PRUEBA
# $s2 --> filas
# $s3 --> columnas
# $s4 --> índice fila
# $s7 --> dirección de la matriz
ordenacion_burbuja:
	
	lw $s2, 0($s7) #filas
	#std::cout << "\nIndice de fila: ";
	li $v0, 4
	la $a0, str_indFila
	syscall

	#std::cin >> indFil;
	li $v0, 5
	syscall
	move $s4, $v0

	#if ((indFil < 0) || (indFil >= matTrabajo->nFil)) {
	slt $t0, $s4, $zero
	sge $t1, $s4, $s2
	or $t0, $t0, $t1
	bnez $t0, error_fila

	move $a0, $s7 #dirección
	move $a2, $s4 #índice fila
	
	jal sort_row

	j while
ordenacion_burbuja_fin:


sort_row:
		
	la $t0, 8($a0) #Primer elemento
	lw $t1, 0($a0) #nFil
	lw $t2, 4($a0) #nColum
	
	addi $t3, $t2, -1 #nCol - 1
	move $t9, $a2 #índice fila


	
	mul $t8, $t1,$t2
	beqz $t8, salir_sort_row

	move $t4, $zero # inicializo el índice de filas a 0 (i)

# for(int f = 0; f < nFil; f++) {
for_sort: 
	move $t5, $zero # inicializo el índice de columnas a 0 (j)
	

segundo_for_sort:
	#hallo la posición del primer elemento
	mul $t7, $a2, $t2 #nCol * índFila
	add $t7, $t7, $t5 #nCol * indFila + j
	mul $t7, $t7, sizeF
	addu $t7, $t7, $t0
	l.s $f4, 0($t7)

	#hallo el del segundo
	mul $t8, $t9, $t2
	add $t8, $t8, $t5
	addi $t8, $t8, 1
	mul $t8, $t8, sizeF
	addu $t8, $t8, $t0
	l.s $f5, 0($t8)

	#comparo el valor de los dos
	c.le.s $f4, $f5
	bc1t salto_sort # si no se cumple que sea mayor se salta el if
	move $a0, $t7
	move $a3, $t8
	
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal swap
	lw $ra, 0($sp)
	addi $sp, $sp, 4

salto_sort:
	
	sub $t6, $t3, $t4 #nCol - 1 - i
	addi $t5, $t5, 1 # j++
	blt $t5, $t6, segundo_for_sort

	addi $t4, $t4, 1 # i++
	blt $t4, $t3, for_sort


salir_sort_row:

	jr $ra
sort_row_fin:

termina_programa:
	li $v0, 4
	la $a0, str_termina
	syscall
	
	li $v0, 10
	syscall