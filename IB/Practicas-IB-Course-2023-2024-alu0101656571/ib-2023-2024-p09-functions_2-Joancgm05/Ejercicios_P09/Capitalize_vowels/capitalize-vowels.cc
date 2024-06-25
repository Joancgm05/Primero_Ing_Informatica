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
#include <cctype> // Para la función std::isalpha y std::toupper
#include "tool.h"
/**
 * @brief Función para capitalizar las vocales en una cadena
 */
/*void capitalizeVowels(std::string& str) {
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
*/
int main() {
  std::string input;

  std::cout << "Ingrese una cadena sin espacios: ";
  std::cin >> input;

  capitalizeVowels(input);

  std::cout << input << std::endl;

    return 0;
}
 
