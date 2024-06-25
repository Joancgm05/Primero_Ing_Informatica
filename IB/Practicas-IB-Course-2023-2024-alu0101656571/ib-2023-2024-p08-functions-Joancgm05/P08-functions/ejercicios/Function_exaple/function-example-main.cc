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
#include <cmath>
#include "function-example.h"

double CalculateFunction(double number_one, double number_two, double number_three) {
  double raiz_cuadrada = sqrt(((2 * number_three) - 4));
  double cuadrado = ((number_one * number_one) - (number_two * number_two));
  double function = raiz_cuadrada / cuadrado;
  return function;
}

int main() {
  double numero_uno, numero_dos, numero_tres;
  std::cin >> numero_uno >> numero_dos >> numero_tres;
  std::cout << CalculateFunction(numero_uno, numero_dos, numero_tres) << '\n';
  return 0;
} 
