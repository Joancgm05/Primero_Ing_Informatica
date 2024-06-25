/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 29 oct 2023
 * @brief this program converts a decimal number into binaty
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */
 
#include <iostream>

void DecimalToBinary(int decimal) {
  if (decimal == 0) {
    std::cout << "0" << '\n';
    return;
  }
  int binary[32];
  int index{0};
  while (decimal > 0) {
    binary[index] = {decimal % 2};
    decimal /= 2;
   ++index;
  }
  for (int i = index - 1; i >= 0; --i) {
    std::cout << binary[i];
  }
  std::cout << '\n';
}
  
int main() {
  int numero_decimal;
  std::cin >> numero_decimal;
  DecimalToBinary(numero_decimal);
  return 0;
}
