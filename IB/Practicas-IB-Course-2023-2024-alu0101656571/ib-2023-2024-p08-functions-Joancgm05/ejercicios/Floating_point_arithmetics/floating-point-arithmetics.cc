/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 5 oct 2023
 * @brief this program says if two numbers are or not equals
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>
#include "are-equal.h"

int main() {
  double numero1, numero2;
  std::cin >> numero1 >> numero2;
  bool result = AreEqual(numero1, numero2);
  if (result) {
  std::cout << "true" << '\n';
  }
  else {
  std::cout << "false" << '\n';
  }
}
