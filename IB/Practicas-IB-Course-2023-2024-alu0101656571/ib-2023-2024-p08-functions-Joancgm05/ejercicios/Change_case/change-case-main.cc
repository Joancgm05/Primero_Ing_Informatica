/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date
 * @brief
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>
#include <string>
#include "change-case.h"

std::string ChangeCase(std::string palabra) {
  for (char& c : palabra) {
    if (std::islower(c)) {
      c = std::toupper(c);
    }
    else if (std::isupper(c)) {
      c = std::tolower(c); 
    }
  }
  return palabra;
}

int main() {
  std::string palabra;
  std::cin >> palabra;
  std::cout << ChangeCase(palabra) << '\n';
  return 0;
}
