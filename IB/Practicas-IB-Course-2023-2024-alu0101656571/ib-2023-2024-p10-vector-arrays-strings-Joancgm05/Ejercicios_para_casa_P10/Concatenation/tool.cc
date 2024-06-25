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
#include "tool.h"

std::vector<int> ConcatenarVectores(const std::vector<int>& vector1, const std::vector<int>& vector2) {
  std::vector<int> resultado;
  resultado.insert(resultado.end(), vector1.begin(), vector1.end());
  resultado.insert(resultado.end(), vector2.begin(), vector2.end());
  return resultado;
}
 
