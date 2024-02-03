# EN C++

if ($s0 != $s1) {
    # Si se cumple la condición entonces:
    $s3 = $s1;
} else {
    # Si no se cumple la condición
    $s3 = 0;
    }
# Después del if

# EN MIPS
# Sin invertir

if:
    bne     $s0, $s1, if_then
    b       if_else
if_then:
    # Si se cumple la condición entonces:
    move    $s3, $s1
    b       if_fin
if_else:
    # Si no se cumple la condición entonces:
    move    $s3, &s0
    b       if_fin
if_fin:
    # después del if

# Invirtiendo

if:
    beq     $s0, $s1, if_else
    # Si se cumple la condición
    move    $s3, $s1
    beq     if_fin
if_else:
    # Si no se cumole la condición
    move    $s3, $s0
if_fin:
    # Después del if 