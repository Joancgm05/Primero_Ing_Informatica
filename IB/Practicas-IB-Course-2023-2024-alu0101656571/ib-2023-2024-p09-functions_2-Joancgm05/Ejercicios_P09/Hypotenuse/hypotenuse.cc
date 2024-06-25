/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @datei 12 nov 2023
 * @brief programa que imprime en pantalla el resultado de la
          hipotenusa dado por la raiz cuadrada de la suma de
          sus dos catetos al cuadrado.
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */
 

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "tool.h"

/*double CalcularHipotenusa(int cateto1, int cateto2) {
  double result = sqrt(cateto1 * cateto1 + cateto2 * cateto2);
  return result;
}
*/
int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "no se han introducido los parámetros propuestos" << '\n';
    return 1;
  }
  int cateto_uno{std::atoi(argv[1])};
  int cateto_dos{std::atoi(argv[2])};
  std::cout << CalcularHipotenusa(cateto_uno, cateto_dos) << '\n';
  return 0;
}
