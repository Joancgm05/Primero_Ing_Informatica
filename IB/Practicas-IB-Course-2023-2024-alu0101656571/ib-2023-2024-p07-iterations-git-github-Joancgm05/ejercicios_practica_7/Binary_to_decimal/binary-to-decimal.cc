/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 29 oct 2023
 * @brief this program reads a binary number, converts it in a
          decimal number and prints that decimal number in the
          screen
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>

bool NoTiene01(int numero) {
  while (numero > 0) {
    int digito = numero % 10;
    if (digito != 0 && digito != 1) {
      return false;
    }
    numero /= 10;
  }
  return true;
}

int main() {
  int numero;
  int decimal{};
  std::cin >> numero;

  if (NoTiene01(numero)) {
    while (numero != 0) {
      if (numero >= 10000000) {
        numero -= 10000000;
        decimal += 128;
      } else if (numero >= 1000000) {
          numero -= 1000000;
          decimal += 64;
      } else if (numero >= 100000) {
          numero -= 100000;
          decimal += 32;
      } else if (numero >= 10000) {
          numero -= 10000;
          decimal += 16;
      } else if (numero >= 1000) {
          numero -= 1000;
          decimal += 8;
      } else if (numero >= 100) {
          numero -= 100;
          decimal += 4;
      } else if (numero >= 10) {
          numero -= 10;
          decimal += 2;
      } else if (numero >= 1) {
          numero -= 1;
          decimal += 1;
      }
    }
    std::cout << decimal << '\n';
  }
  else {
    std::cerr << "Wrong input" << '\n';
  }
  return 0;
}
  
