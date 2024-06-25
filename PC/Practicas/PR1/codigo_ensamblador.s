.data
    titulo:    .asciiz "\nPR1: Principio de computadores.\n"
    pet:       .asciiz "\nIntroduzca maximo error permitido: "
    caderr:    .asciiz "\nError: el dato introducido debe cumplir 0.00001 <= dato < 1\n"
    cade:      .asciiz "\nNumero e: "
    cadnt:     .asciiz "\nNumero de terminos: "
    cadfin:    .asciiz "\nPR1: Fin del programa.\n"

    # Variables
    #error --> $f20
    #n_E --> $f22
    #numero_factorial --> $f24
    #numero_terminos --> $f26
    #ultimo_termino --> $f28

.text
main:
    #  std::cout << "PR1: Principios de computadores." << std::endl;
    li $v0, 4
    la $a0, titulo
    syscall
    b while
error:
    # std::cout << "\nError: el dato introducido debe cumplir 0.00001 <= dato < 1" << std::endl;
    li $v0, 4
    la $a0, caderr
    syscall
while:
    # std::cout << "\nIntroduzca maximo error permitido: ";
    li $v0, 4
    la $a0, pet
    syscall
    #  std::cin >> error;
    li $v0, 7
    syscall
    mov.d $f20,$f0

    # if (error >= 0.00001 && error < 1) {
    li.d $f4, 0.00001
    c.lt.d $f20, $f4
    bc1t error
    li.d $f6, 1.0
    c.lt.d $f20, $f6
    bc1f error

    li.d $f22, 1.0 #n_E
    li.d $f24, 1.0 #numero_factorial
    li.d $f26, 1.0 #numero_terminos
    li.d $f28, 1.0 #ultimo_termino
while_loop:
    li.d $f8, 1.0
    mul.d $f24, $f24, $f26      # numero_factorial *= numero_terminos;
    div.d $f28, $f8, $f24      # ultimo_termino = 1.0 / numero_factorial;
    add.d $f22, $f22, $f28      # n_E += ultimo_termino;
    add.d $f26, $f26, $f8      # numero_terminos++;
    #while (ultimo_termino >= error)
    c.lt.d $f28, $f20
    bc1f while_loop

    #std::cout <<  "\nNumero e: ";
    #std::cout << std::fixed << std::setprecision(17) << n_E << std::endl;
    li $v0, 4
    la $a0, cade
    syscall

    li $v0, 3
    mov.d $f12, $f22
    syscall

    #std::cout << "Numero de terminos: " << static_cast<int>(numero_terminos) << std::endl;
    li $v0, 4
    la $a0, cadnt
    syscall

    li $v0, 3
    mov.d $f12, $f26
    syscall

    #  std::cout << "PR1: Fin del programa.\n";
    li $v0, 4
    la $a0, cadfin
    syscall

    # Salir del programa
    li $v0, 10
    syscall

