/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date this program reads two natural numbers a and b, with 
         b > 0, and prints the integer division d and the 
         remainder r of a divided by b.
 * @brief Oct 28th 2023
 * @bug there are no bugs
 *
 * @see https://jutge.org/problems/P48107_en
 */

#include <iostream>

int main() {
  int dividendo, divisor;
  std::cin >> dividendo >> divisor;
  if (divisor < 1 || dividendo < 0) {
  std::cerr << "error" << '\n';
  return 1;
  }
  std::cout << dividendo / divisor << " " << dividendo % divisor << '\n';
  return 0;
} 
