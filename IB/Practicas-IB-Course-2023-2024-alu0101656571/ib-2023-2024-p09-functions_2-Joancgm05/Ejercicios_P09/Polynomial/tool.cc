/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 11 nov 2023
 * @brief funcion para calcular el polinomio
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>
#include <vector>
#include "tool.h"

double calculatePolynomial(const std::vector<double>& coefficients, double value) {
  double result = coefficients[0];
    for (size_t i = 1; i < coefficients.size(); ++i) {
      result = result * value + coefficients[i];
    }   

    return result;
}
 
