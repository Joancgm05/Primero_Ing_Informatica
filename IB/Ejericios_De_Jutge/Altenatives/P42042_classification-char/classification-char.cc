/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date OCt 28th 2023
 * @brief this program tell if the letter is uppercase or 
          lowercase, and also tell if it is a vowel or a 
          consonant.
 * @bug there are no bugs
 *
 * @see https://jutge.org/problems/P42042_en
 */

#include <iostream>

int main() {
  char caracter {};
  std::cin >> caracter;
  caracter = static_cast<int>(caracter);
  if (caracter >= 97) {
  std::cout << "lowercase" << '\n';
  }
  else {
    if (caracter < 97) {
    std::cout << "uppercase" << '\n';
    }
  }
  if (caracter == 65 || caracter == 69 || caracter == 73 || 
      caracter == 79 || caracter == 85 || caracter == 97 ||
      caracter == 101 || caracter == 105 || caracter == 69
      || caracter == 111 || caracter == 117) {
  std::cout << "vowel" << '\n';
  }
  else {
  std::cout << "consonant" << '\n';
  }
  return 0;
}
