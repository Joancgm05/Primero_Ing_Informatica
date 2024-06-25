/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date
 * @brief
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>
#include <vector>
#include "reduce.h"

float ReduceSum(const std::vector<float>& vector) {
  float suma = 0.0;
  for (float numero : vector) {
    suma += numero;
  }
  return suma;
}

int main() {
  int tamano;
  std::cout << "ingrese el tamaño del vector: ";
  std::cin >> tamano;
  std::vector<float> numeros;
  for (int i = 0; i < tamano; ++i) {
    float numero;
    std::cout << "Ingrese el elemento " << i + 1 << ": ";
    std::cin >> numero;
    numeros.emplace_back(numero);
  }
  float sumaTotal = ReduceSum(numeros);
  std::cout << "La suma de los valores en el vector es: " << sumaTotal << std::endl;
  return 0;
}
 
