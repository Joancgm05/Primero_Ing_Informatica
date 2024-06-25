/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 3 nov 2023
 * @brief the function ChangeCas the function ChangeCasee
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

