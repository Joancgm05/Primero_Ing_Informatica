/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date Oct 27th 2023
 * @brief this program print a line with the maximum of the 
          three numbers.
 * @bug there are no bugs
 *
 * @see https://jutge.org/problems/P52847_en
 */
 
#include <iostream>

int main() {
  int numero_uno, numero_dos, numero_tres;
  std::cin >> numero_uno >> numero_dos >> numero_tres;
  int numero_maximo {numero_uno};
  if (numero_dos > numero_maximo && numero_dos != numero_maximo) {
  numero_maximo = numero_dos;
  }
  if (numero_tres > numero_maximo && numero_tres != numero_maximo) {
  numero_maximo = numero_tres;
  }
  std::cout << numero_maximo << '\n';
  return 0;
}
 
 
