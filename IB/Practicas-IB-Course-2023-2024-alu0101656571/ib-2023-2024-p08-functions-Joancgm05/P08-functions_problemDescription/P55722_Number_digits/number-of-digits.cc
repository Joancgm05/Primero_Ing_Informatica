/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 6 nov 2023
 * @brief this program reads a number and prints in the screen
          how many caracters have
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */
 
#include <iostream>

int number_of_digits(int n) {
  int temp{};
  for (int i{n}; i / 10 >= 0; ++temp) {
  }
  return temp;
}
int main() {
  int numero;
  std::cin >> numero;
  std::cout << number_of_digits(numero) << '\n';
  return 0;
}
