/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 27 nov 2023
 * @brief este program lee un fichero y expulsa otro.
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream inf{ "fichero-de-texto.txt" };
  if (!inf) {
    std::cerr << "no se ha utilizado un archivo" << '\n';
    return 1;
  }
  while (inf) {
    std::string word;
    std::getline(inf, word);
    std::cout << word << '\n';
  }
  return 0;
}
  

