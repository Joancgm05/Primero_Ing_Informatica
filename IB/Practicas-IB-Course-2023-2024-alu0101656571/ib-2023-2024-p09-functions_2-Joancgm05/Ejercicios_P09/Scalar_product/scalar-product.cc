/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 11 nov 2023
 * @brief programa que calcula el producto vectorial de dos 
          vectores
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>
#include <vector>
#include "tool.h"

int main() {
  int numero_elementos{};
  std::cout << "inserte el numero de elementos de los vectores" << '\n';
  std::cin >> numero_elementos;
  
  std::vector<double> vectorA;
  for (int i{0}; i < numero_elementos; ++i) {
    int valor;
    std::cout << "Ingrese un valor para la posición " << i << ": ";
    std::cin >> valor;
    vectorA.emplace_back(valor);
  }
  
  std::vector<double> vectorB;
  for (int i{0}; i < numero_elementos; ++i){
    int valor;
    std::cout << "Ingrese un valor para la posición " << i << ": ";
    std::cin >> valor;
    vectorB.emplace_back(valor);
  }
  double resultado = CalcularProductoEscalar(vectorA, vectorB);

  if (resultado != 0.0) {
    std::cout << "El producto escalar es: " << resultado << std::endl;
  }

  return 0;
}
 
