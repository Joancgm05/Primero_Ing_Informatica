/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
  * @date Oct 8 2023
  * @brief The program prints the result of the calculation of
  *        the area and the perimeter of a square being given
  *        the side
  *
  * @bug There are no known bugs
  */


#include <iostream>

int main() {
  int lado;
  std::cout << "Escribe la longitud del lado del cuadrado." << std::endl;
  std::cin >> lado;
  std::cout << "El área del cuadrado es " << lado * lado
	    << " y el perímetro es " << lado * 4 << std::endl;
  
  return 0;
}
