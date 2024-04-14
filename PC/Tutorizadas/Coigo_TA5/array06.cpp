// Autor: Alberto Hamilton Castro
// Fecha: 2023-03-21

// Ejemplo sencillo de uso de array: array doubles

#include <iostream>

int main() {
  int numElem = 6;
  double vectD[numElem] = {-2.03, 10.33, 4.85, 3e-10, 7.5e+5, 9.022};
  
  for(int i = 0; i < numElem; i++) {
    double valor = vectD[i];
    std::cout << "\nvectF["  << i << "] = " << valor;
  }
  std::cout << "\nTermina el programa\n";
} 
