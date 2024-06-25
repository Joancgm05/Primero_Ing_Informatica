/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 11 nov 2023
 * @brief funcion que calcula el producto escalar de dos vectores
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <vector>
#include <iostream>
#include "tool.h"
 
/**
 * @brief Función para calcular el producto escalar de dos vectores
 */
double CalcularProductoEscalar(const std::vector<double>& vector1, const std::vector<double>& vector2) {
  // Verificar si los vectores tienen la misma longitud
  if (vector1.size() != vector2.size()) {
    std::cerr << "Error: Los vectores no tienen la misma longitud." << std::endl;
    return 0.0;
  }
  // Calcular el producto escalar
  double productoEscalar {0.0};
  for (size_t i = 0; i < vector1.size(); ++i) {
    productoEscalar += vector1[i] * vector2[i];
  }

  return productoEscalar;
}

