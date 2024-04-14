// Autor: Alberto Hamilton Castro
// Fecha: 2023-03-21

// Ejemplo sencillo de uso de array: lectura

#include <iostream>

#define N 10

int main() {
  int vect[N] = {7, 2, 6, 8, 1, 9, 10, 3, 4, 5};
  
  int indice = 3;
  
  int valor = vect[indice];

  std::cout << valor << "\n";
  
  valor = vect[6];

  std::cout << valor << "\n";
} 
