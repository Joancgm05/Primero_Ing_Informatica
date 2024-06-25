/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 11 nov 2023
 * @brief funcion para capitalizar letras
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>
#include <cctype> 
#include "tool.h"

void capitalizeVowels(std::string& str) {
  for (char& c : str) {
    if (std::isalpha(c)) { // Verifica si es una letra
      // Convierte la letra a minúscula
      c = std::tolower(c);
    
     // Si la letra es una vocal, la convierte a mayúscula
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        c = std::toupper(c);
      }   
    }   
  }
}
 
