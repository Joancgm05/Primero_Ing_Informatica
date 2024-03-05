/*
Enunciado:
Realizar un programa que haga lo siguiente:
1) Pedir al usuario que introduzca por teclado dos números enteros x y c.
2) comprobar que x es mayor o igual que cero, y que c es mayor o igual que cero y menor o igual que nueve.
3) Si se cumple la condición descrita en el punto 2, el programa debe contar el número de veces que 
   aparece la cifra c, en el número x, mostrar el resultado por pantalla y volver al punto 1.
4) Si no se cumple la condición descrita en el punto 2, el programa debe finalizar.

Por ejemplo si el usuario introduce como x el valor 12242 y como c el valor 2, 
debe imprimir por la pantalla el número 3 (que es las veces que aparece 2 en 12242).
*/

#include <iostream>
int main() {
    int x, c;
    int cuenta = 0;

    while (true) {
        std::cout << "Este programa cuenta el numero de veces que aparece una cifra en un numero entero positivo.\n";
        std::cout << "Introduzca un numero entero positivo (introduzca negativo para finalizar el programa): ";
        std::cin >> x;
        if (x < 0) break;
        std::cout << "Introduzca la cifra (0-9, introduzca otra cosa para finalizar el programa): ";
        std::cin >> c;
        if ((c < 0) || (c > 9)) break;
        cuenta = 0;
        int resto;
        while ( x != 0 ) {
            resto = x % 10;
            x /= 10;
            if ( resto == c ) cuenta++;
        }
        std::cout << "El numero de veces que aparece la cifra en el numero es: " << cuenta << std::endl;
    }
    std::cout << "Fin del programa.\n";
    return 0;
}
