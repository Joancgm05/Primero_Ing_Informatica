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

/*double calculatePolynomial(const std::vector<double>& coefficients, double value) {
  double result = coefficients[0];
    for (size_t i = 1; i < coefficients.size(); ++i) {
      result = result * value + coefficients[i];
    }

    return result;
}
*/
int main() {
  std::cout << "ingrese el numero de elementos del vector" << '\n';
  int numero_elementos;
  std::cin >> numero_elementos;
  
  std::vector<double> coefficients;
  for (int i{0}; i < numero_elementos; ++i) {
    int valor;
    std::cout << "Ingrese un valor para la posicion" << i + 1 << ": ";
    std::cin >> valor;
    coefficients.emplace_back(valor);
  }
  double xValue;
  std::cout << "Ingrese el valor de x para evaluar el polinomio: ";
  std::cin >> xValue;

  double result = calculatePolynomial(coefficients, xValue);
  std::cout << "Resultado del polinomio para x = " << xValue << ": " << result << std::endl;

  return 0;
}

