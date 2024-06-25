/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date Oct 27th 2023
 * @brief Write a program that reads a letter and prints it in 
          lowercase if it was uppercase, or prints it in uppercase 
          if it was lowercase
 * @bug there are no bugs
 *
 * @see https://jutge.org/problems/P98960_en
 */
 
#include <iostream>

int main() {
  char caracter {};
  std::cin >> caracter;
  caracter = static_cast<int>(caracter);
  if (caracter >= 97)  {
  caracter = caracter - 32;
  }
  else {
  caracter = caracter + 32;
  }
  caracter = static_cast<char>(caracter);
  std::cout << caracter << '\n';
  return 0;
}
