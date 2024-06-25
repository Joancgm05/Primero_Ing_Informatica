/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date
 * @brief this program reads an integer number a and a natural 
          number b, with b > 0, and prints the integer division 
          d and the remainder r of a divided by b.
 * @bug there are no bugs
 *
 * @see https://jutge.org/problems/P92351_en
 */
 
#include <iostream> 

int main() {
  int dividendo, divisor;
  std::cin >> dividendo >> divisor;
  if (divisor < 1) {
  std::cerr << "error" << '\n';
  return 1;
  }
  int cociente {dividendo / divisor};
  int resto = {dividendo % divisor};
  std::cout << cociente << " " << resto << '\n';
  return 0;
}
