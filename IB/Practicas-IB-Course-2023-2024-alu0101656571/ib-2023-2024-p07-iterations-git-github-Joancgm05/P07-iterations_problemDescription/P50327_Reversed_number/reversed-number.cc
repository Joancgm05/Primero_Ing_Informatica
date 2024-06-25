/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 30 oct 2023
 * @brief this program reads a number and prints it reversed
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>

void ReversedNumber(int number) {
  int almacenar_numero[8];
  int cero{0};
  while (number > 0) {
    almacenar_numero[cero] = number % 10;
    number /= 10;
    cero++;
  }
  for (int i = cero - 1; i >= 0; --i) {
    std::cout << almacenar_numero[i];
  }
  std::cout << '\n';
}

int main() {
  int numero;
  std::cin >> numero;
  ReversedNumber(numero);
  std::cout << '\n';
  return 0;
}

