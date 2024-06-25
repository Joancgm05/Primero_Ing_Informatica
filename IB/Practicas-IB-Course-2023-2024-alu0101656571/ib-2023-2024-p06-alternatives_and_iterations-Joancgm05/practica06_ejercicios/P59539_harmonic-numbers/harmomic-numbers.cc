/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 * 
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date oct 22th 2023
 * @brief this program reads a number n and prints the n-th 
          harmonic number, defined as Hn = 1/1 + 1/2 + ⋯ + 1/n.
 * @bug 0 bugs
 * @see https://jutge.org/problems/P97156_en
 */

#include<iostream>
#include<iomanip>

int main() {
  int number;
  double harmonic {0.0};
  std::cin >> number;

  for (int increment = 1; increment <= number; increment++) {
  harmonic += 1.0 / increment;
  }
  std::cout << std::fixed << std::setprecision(4);
  std::cout << harmonic << '\n';

  return 0;
} 
