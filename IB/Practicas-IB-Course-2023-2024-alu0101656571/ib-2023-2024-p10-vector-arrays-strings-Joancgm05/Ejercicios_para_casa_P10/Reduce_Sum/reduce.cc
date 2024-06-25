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
#include <vector>
#include "reduce.h"

float ReduceSum(const std::vector<float>& vector) {
  float suma = 0.0;
  for (float numero : vector) {
    suma += numero;
  }
  return suma;
}
 
