# EN C++

suma = 0;

for (int i = 0; i <= 100, ++i) {
    suma += i;
}
# Después del for

# EN MIPS

# Sin invertir 

# suma = $s0
# i    = $t0
#i → $t0 no hay llamadas syscall ni funciones

    move    $s0, $zero
    move    $t0, $zero # Inicialización i = 0

for: 
    # Condición: entramos si i <= 100
    ble     $t0, 100, for_dentro
    b       for_fin
for_dentro:
    add     $s0, $s0, $t0
    addi    $t0, $t0, 1 # Actualización ++i
    b       for # Vuelta a la condición
for_fin:
    # Después for

# Invirtiendo

# suma = $s0
# i    = $t0
# i → $t0 no hay llamadas syscall ni funciones

    move $so, $zero
    move $s0, $zero 

for:
    # Condición invertida: salimos si i > 100
    bgt     $t0, 100, for_fin

    add     $s0, $s0, $t0
    addi    $t0, $t0, 1 # Actualización ++i
    b       for: # Vuelta a la condición
for_fin:
    

