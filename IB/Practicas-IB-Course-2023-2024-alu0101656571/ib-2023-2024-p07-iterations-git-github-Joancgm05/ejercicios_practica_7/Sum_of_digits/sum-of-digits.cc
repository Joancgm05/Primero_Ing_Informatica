/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 29 oct 2023
 * @brief this program reads two natural numbers and prints 
          their sum
 * @bug there are no bugs
 */

#include <iostream>

int SumOfDigits(int numero) {
  int suma{};
  if (numero < 0) {
    std::cerr << "error" << '\n';
  }
  else {
    int temp{numero};
    while (temp > 0) {
      int digito{temp % 10};
      suma += digito;
      temp /= 10;
    }
  }
  return suma;
}

int main() {
  int num_uno;
  std::cin >> num_uno;
  std::cout << SumOfDigits(num_uno) << '\n';
  return 0;
} 
