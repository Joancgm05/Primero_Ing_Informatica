/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date Oct 27th 2023
 * @brief This program write a program that reads an integer number that 
          represents a temperature given in degree Celsius, 
          and that tells if the weather is hot, if it’s cold, 
          or if it’s ok. Suppose that it’s hot if the temperature 
          is higher than 30 degrees, that it’s cold if the temperature 
          is lower than 10 degrees, and that it’s ok otherwise. 
          Moreover, warn if with the given temperature water would 
          boil, or if water would freeze. Assume that water boils 
          at 100 or more degrees, and that water freezes at 0 or 
          less degrees.
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */
 
#include <iostream>

int main() {
  int temperatura {};
  std::cin >> temperatura;
  if (temperatura > 30) {
  std::cout << "it's hot" << '\n';
  }
  if (temperatura < 10) {
  std::cout << "it's cold" << '\n';
  }
  if (temperatura >= 10 && temperatura <= 30) {
  std::cout << "it's ok" << '\n';
  }
  if (temperatura >= 100) {
  std::cout << "water would boil" << '\n';
  }
  if (temperatura <= 0) {
  std::cout << "water would freeze" << '\n';
  }
  return 0;
}
