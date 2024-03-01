/* 
 * File:   repasotablas.cpp
 * Authores: Carlos y Alberto
 *
 * Descripción: El usuario introducira por teclado la tabla de multiplicar que
 * quiere repasar. Si introduce un 0 el programa finalizara. Si introduce un
 * numero mayor que 0 debera pregutar al usuario por todas las multiplicaciones
 * del numero introducido por lo numero del 1 al 10. Al final de cada tabla se
 * visualizara el porcentaje de aciertos.
 */
#include <iostream>

int main(int argc, char** argv) {

  std::cout << "Programa para repasar las tablas de multiplicar.\n";
  int n; // numero del que quiero repasar la tabla
  do {
    std::cout<<"¿Qué tabla deseas repasar? Introduce un número (0 para salir): ";
    std::cin >> n;
    if (n == 0) break; // si introduce un 0 sale del bucle
    int aciertos = 0; // incializamos el numero de aciertos
    for (int i = 1; i <= 10; i++) {
      std::cout << i << " x " << n << " ? ";
      int resultado;
      std::cin >> resultado;
      if (resultado == (i * n)) {
        aciertos++;
      }
    }
    int porcentaje = aciertos * 10;
    std::cout << "Tu porcenaje de aciertos es del " << porcentaje << "%\n";
  } while (n != 0);
  std::cout << "Termina el programa.\n";
}
