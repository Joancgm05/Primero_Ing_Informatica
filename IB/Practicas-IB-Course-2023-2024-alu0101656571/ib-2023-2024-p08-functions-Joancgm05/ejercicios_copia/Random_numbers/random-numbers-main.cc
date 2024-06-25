/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 3 oct 2023
 * @brief 
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */
 
#include <cstdlib>
#include <iostream>

double RandomNumber(int numero_uno, int numero_dos) {
  std::srand(0);
  double r = numero_uno + (std::rand() / (double)RAND_MAX) * (numero_dos - numero_uno);
  return r;
}

int main() {
  int number_one, number_two;
  std::cin >> number_one >> number_two;
  std::cout << RandomNumber(number_one, number_two) << '\n';
  return 0;
} 
