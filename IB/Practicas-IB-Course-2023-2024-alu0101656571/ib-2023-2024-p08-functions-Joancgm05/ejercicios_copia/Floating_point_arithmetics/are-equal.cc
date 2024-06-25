/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 5 noc 2023
 * @brief function "AreEqual"
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <cmath>
#include "are-equal.h"

bool AreEqual(const double number1, const double number2, const double epsilon = 1e-7) {
  return std::abs(number1 - number2) < epsilon;
}
 
