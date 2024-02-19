#include <iostream>
#include <vector>

int main() {
  int vector[] = {1, 2, 3, 4, 5, 6, 7};
  int *ptri, *ptrf, aux;
  ptri = vector; // Este puntero apunta al comienzo del vector
  ptrf = vector + 6; // Este puntero apunta al final del vector
  while (ptri < ptrf) {
    aux = *ptri; // Guardo el vector del inicio en aux
    *ptri = *ptrf; // Intercambio los valores del puntero del inicio y el del fin
    *ptrf = aux;
    ++ptri; // Aumento la posición a la que apunta
    --ptrf; // Decremento la posición a la que apunta
  }
  
  for (int i{0}; i < 7; ++i) {
    if (i == 6) {
      std::cout << vector[i] << ".";
    } else {
        std::cout << vector[i] << ", ";
      }
  }
  return 0;
}