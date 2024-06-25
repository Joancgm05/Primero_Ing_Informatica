// Autor: Alberto Hamilton Castro
// Fecha: 2023-03-21

// Ejemplo sencillo de uso de array: array floats

#include <iostream>

int main() {
  int numElem = 5;
  float vectF[numElem] = {1.1, 2.2, 3.3, 4.4, 5.5};
  
  for(int i = 0; i < numElem; i++) {
    float valor = vectF[i];
    std::cout << "\nvectF["  << i << "] = " << valor;
  }
  std::cout << "\nTermina el programa\n";
} 
