/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 * 
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date oct 22th 2023
 * @brief Descripción
 * @bug 0 bugs
 * @see https:g/jutge.org/problems/
 */

#include<iostream>

int main() {
  char letter;
  std::cin >> letter;
  letter = static_cast<int>(letter);
  
  if (letter < 97) {
  letter = letter + 32;
	std::cout << static_cast<char>(letter) << '\n';
	}
  else {
    if (letter >= 97) {
    letter = letter - 32;
    std::cout << static_cast<char>(letter) << '\n';
		}
	}
  
  return 0;
}
