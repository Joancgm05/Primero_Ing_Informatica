# EN C++

suma = 0;
std::cin >> numero;

while (numero > 0) {
    # Interior del while
    suma += numero;
    std::cin >> numero;
}
# Después del while

# EN MIPS
# Sin invertir

# suma       $s0
# numero     $v0
    move        $s0, $zero

    # Leo entero por consola
    li          $v0, 5
    syscall     # Entero en $v0

while:
    # Salimos si numero <= 0
    bgtz        $v0, while_dentro
    b           while_fin
while_dentro:
    # Interior del while
    add         $s0, $s0, $v0
    # Leo entero por consola
    li          $v0, 5
    syscall     # Entero en $v0
    b           while # Vuelvo al inicio
while_fin:
    # Después while

# Invirtiendo

#suma       $s0
#numero     $v0
    move        $s0, $zero

    # Leo entero por consola
    li          $v0, 5
    syscall     # Entero en $v0

while: 
    # Salimos si el número es <= 0
    blez        $v0, while_fin
    
    # Interior del while
    add         $s0, $s0, $v0
    # Leo entero por consola    
    li          $v0, 5
    syscall     # Entero en $v0
    b           while
while_fin:
    # Después while

# Otra opción

#suma       $s0
#numero     $v0
    move        $s0, $zero

    # Leo entero por consola
    li          $v0, 5
    syscall     # Entero en $v0

    # Saltamos a condición del while
    b           while_condicion
while:
    # Interior del while
    add         $s0, $s0, $v0
    # Leo entero por consola
    li          $v0, 5
    syscall     # Entero en $v0
while_condicion:
    # Repetimos si numero > 0
    bgtz        $v0, while
while_fin:
    # Después while