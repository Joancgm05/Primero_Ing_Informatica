// Autor: Alberto Hamilton Castro
// Fecha: 2023-03-21

// Ejemplo sencillo de uso de array: numero elementos en variable

#include <iostream>

int main() {
  int numElem = 10;
  int vect[numElem] = {7, 2, 6, 8, 1, 9, 10, 3, 4, 5};
  
  for(int i = 0; i < numElem; i++) {
    int valor = vect[i];
    std::cout << "\nvect["  << i << "] = " << valor;
  }
  std::cout << "\nTermina el programa\n";
} 
