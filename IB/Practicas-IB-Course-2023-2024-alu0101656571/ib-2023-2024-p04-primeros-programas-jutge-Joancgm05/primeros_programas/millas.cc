/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
  * @date Oct 8 2023
  * @brief The program calculates how many kilometers are "ml"
  *        number of miles 
  *
  * @bug There are no known bugs
  */


#include <iostream>

int main() {
  float ml, km;
  std::cin >> ml;
  km = ml * 1.609;
  std::cout << "Son " << km << " kilómetros" << std::endl;
 
  return 0;
}
