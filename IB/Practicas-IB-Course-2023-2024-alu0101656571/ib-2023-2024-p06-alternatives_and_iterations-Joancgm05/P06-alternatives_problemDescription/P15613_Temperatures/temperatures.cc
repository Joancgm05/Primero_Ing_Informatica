/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 * 
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date oct 23th 2023
 * @brief that reads an integer number that represents a temperature
          given in degree Celsius, and that tells if the weather is hot,
          if it’s cold, or if it’s ok. Suppose that it’s hot if the temperature
          is higher than 30 degrees, that it’s cold if the temperature is lower
          than 10 degrees, and that it’s ok otherwise. Moreover, warn if with the
          given temperature water would boil, or if water would freeze. Assume that
          water boils at 100 or more degrees, and that water freezes at 0 or less degrees.
 * @bug 0 bugs
 * @see https:g/jutge.org/problems/
 */

#include<iostream>

int main() {

  int temperature;
  std::cin >> temperature;

  if (temperature > 30) {
  std::cout << "it's hot" << '\n';
  }
  if (temperature < 10) {
  std::cout << "it's cold" << '\n';
  }
  if (temperature < 30 && temperature > 10) {
  std::cout << "it's ok" << '\n';
	}
  if (temperature >= 100) {
  std::cout << "water would boil" << '\n';
  }
  if (temperature <= 0) {
  std::cout << "water would freeze" << '\n';
  }
  return 0;
}
