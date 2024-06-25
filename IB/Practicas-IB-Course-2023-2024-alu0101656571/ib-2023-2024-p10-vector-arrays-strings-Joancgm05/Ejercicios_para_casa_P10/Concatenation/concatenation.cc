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
#include "tool.h"

std::vector<int> ConcatenarVectores(const std::vector<int>& vector1, const std::vector<int>& vector2) {
  std::vector<int> resultado;
  resultado.insert(resultado.end(), vector1.begin(), vector1.end());
  resultado.insert(resultado.end(), vector2.begin(), vector2.end());
  return resultado;
}

int main() {
  int tamano1;
  std::cout << "Ingrese el tamaño del primer vector: ";
  std::cin >> tamano1;
  std::vector<int> vector1;
  std::cout << "Ingrese " << tamano1 << " elementos para el primer vector: ";
  for (int i = 0; i < tamano1; ++i) {
    int elemento;
    std::cin >> elemento;
    vector1.push_back(elemento);
  }
  int tamano2;
  std::cout << "Ingrese el tamaño del segundo vector: ";
  std::cin >> tamano2;
  std::vector<int> vector2;
  std::cout << "Ingrese " << tamano2 << " elementos para el segundo vector: ";
  for (int i = 0; i < tamano2; ++i) {
    int elemento;
    std::cin >> elemento;
    vector2.push_back(elemento);
  }
  std::vector<int> resultado = ConcatenarVectores(vector1, vector2);
  std::cout << "Resultado de la concatenación:" << std::endl;
  for (int elemento : resultado) {
    std::cout << elemento << " ";
  }
  std::cout << std::endl;

  return 0;
}
 
