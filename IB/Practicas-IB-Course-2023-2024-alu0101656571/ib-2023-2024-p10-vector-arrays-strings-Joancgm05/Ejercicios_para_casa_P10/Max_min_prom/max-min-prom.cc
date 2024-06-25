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
#include <limits> // Para utilizar std::numeric_limits
#include "tool.h"

void CalcularEstadisticas(const std::vector<double>& vector, double& maximo, double& minimo, double& promedio) {
  if (vector.empty()) {
    std::cout << "El vector está vacío. No se pueden calcular estadísticas." << std::endl;
    return;
  }

  maximo = std::numeric_limits<double>::lowest(); 
  minimo = std::numeric_limits<double>::max();    
  promedio = 0.0;

  for (double numero : vector) {
    if (numero > maximo) {
      maximo = numero;
    }
    if (numero < minimo) {
      minimo = numero;
    }
    promedio += numero;
  }
  promedio /= vector.size();
}

int main() {
  int tamano;
  std::cout << "introduzca el tamaño del vector: ";
  std::cin >> tamano;
  std::vector<double> numeros;
  for (int i = 0; i < tamano; ++i) {
    double numero;
    std::cout << "Ingrese el elemento " << i + 1 << ": ";
    std::cin >> numero;
    numeros.push_back(numero);
  }
  double maximo, minimo, promedio;

  CalcularEstadisticas(numeros, maximo, minimo, promedio);

  std::cout << "Valor máximo: " << maximo << std::endl;
  std::cout << "Valor mínimo: " << minimo << std::endl;
  std::cout << "Promedio: " << promedio << std::endl;

  return 0;
}
 
