/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 12 nov 2023
 * @brief función que se encarga de calcular la hipotenusa
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "tool.h"

double CalcularHipotenusa(int cateto1, int cateto2) {
  double result = sqrt(cateto1 * cateto1 + cateto2 * cateto2);
  return result;
}
 
