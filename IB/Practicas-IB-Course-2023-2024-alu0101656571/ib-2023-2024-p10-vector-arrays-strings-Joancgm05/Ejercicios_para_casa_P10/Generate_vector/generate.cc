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

#include <vector>
#include <random>
#include "generate.h"

std::vector<double> GenerateVector(const int size, const double lower, const double upper) {
  std::random_device rd; 
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(lower, upper);
  std::vector<double> result(size);
  for (int i = 0; i < size; ++i) {
    result[i] = dist(gen);
  }
    
  return result;
}
 
