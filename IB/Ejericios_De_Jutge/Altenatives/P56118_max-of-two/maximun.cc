/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date Oct 27th 2023
 * @brief this program Print a line with the maximum of the 
          two numbers.
 * @bug there are no bugs
 *
 * @see https://jutge.org/problems/P56118_en
 */ 

#include <iostream>

int main() {
  int numero_uno, numero_dos;
  std::cin >> numero_uno >> numero_dos;
  
  if (numero_uno > numero_dos) {
    std::cout << numero_uno << '\n';
  }
  else {
    std::cout << numero_dos << '\n';
  } 
  return 0;
}
