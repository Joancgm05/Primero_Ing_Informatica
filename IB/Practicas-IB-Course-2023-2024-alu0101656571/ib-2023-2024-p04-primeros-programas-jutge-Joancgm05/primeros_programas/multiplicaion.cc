/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
  * @date Oct 8 2023
  * @brief The program prints the result of the calculation of
  *        "numero1" * "numero2"
  *
  * @bug There are no known bugs
  */


#include <iostream>

int main() {
  int numero1;
  int numero2;
  std::cout << "Dime un número." << std::endl;
  std::cin >> numero1;
  std::cout << "Dime otro número." << std::endl;
  std::cin >> numero2;
  std::cout << "Su multiplicación es " << numero1 * numero2 << "." << std::endl;
 
  return 0;
}
