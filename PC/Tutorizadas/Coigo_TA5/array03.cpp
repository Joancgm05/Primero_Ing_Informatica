// Autor: Alberto Hamilton Castro
// Fecha: 2023-03-21

// Ejemplo sencillo de uso de array: recorrido

#include <iostream>

#define N 10

int main() {
  int vect[N] = {7, 2, 6, 8, 1, 9, 10, 3, 4, 5};
  
  for(int i = 0; i < N; i++) {
    int valor = vect[i];
    std::cout << "\nvect["  << i << "] = " << valor;
  }
  std::cout << "\nTermina el programa\n";
} 
