/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 20 nov 2023
 * @brief
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */
 
#include <iostream>
#include <vector>

int main() {
  int numero_natural{0};
  int contador{0};
  std::cin >> numero_natural;
  std::vector<int> numeros;
  for (int i = 0; i < numero_natural; ++i) {
    int numero;
    std::cin >> numero;
    numeros.emplace_back(numero);
  }
  for (int i{0}; i < numero_natural - 1; ++i) {
    if (numeros.back() == numeros[i]) {
      ++contador;
    }
  }
  std::cout << contador << '\n';
  return 0;
}
