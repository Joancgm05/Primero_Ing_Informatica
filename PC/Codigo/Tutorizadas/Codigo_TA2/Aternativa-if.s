# EN C++

if ($s0 != $s1) { 
# si se cumple condición → then 
    $s3 = $s1; 
} 
# después if

# EN MIPS 
# Sin invertir

if:
    bne     $s0, $s1, if_then
    b       if_fin
if_then:
    # Si se cumple la condición entonces: 
    move    $s3, $s1, 
if_fin:
    # Después del fin

# Invirtiendo

if:
    beq     $s0, $s1, if_fin
    # Si se cumple la condición entonces
    move    $s3, $s1
if_fin:
    # Después del if 

    hola q tal