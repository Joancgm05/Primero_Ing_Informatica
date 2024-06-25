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

bool IsAValidTriangle(double a, double b, double c) {
  return a + b > c && a + c > b && b + c > a;
}

double Area(double a, double b, double c) {
  double s = (a + b + c) / 2.0;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
  double a, b, c;
  std::cin >> a >> b >> c;
  if (IsAValidTriangle(a, b, c)) {
    double area = Area(a, b, c);
    std::cout << area << '\n';
  } else {
      std::cout << "Not a valid Triangle" << std::endl;
    }
  return 0;
}
 
