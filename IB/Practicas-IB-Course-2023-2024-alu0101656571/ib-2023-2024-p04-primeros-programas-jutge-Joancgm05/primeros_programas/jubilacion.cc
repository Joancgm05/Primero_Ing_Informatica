/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
  * @date Oct 8 2023
  * @brief The program calcultes the amount of years that you have
  *        to live util your retirement
  *
  * @bug There are no known bugs
  */


#include <iostream>

int main() {
  const int jubilacion = 65;
  int edad;
  std::cout << "Ingresa tu edad." << std::endl;
  std::cin >> edad;
  std::cout << "Te faltan " << jubilacion - edad << " años para jubilarte." << std::endl;
 
  return 0;
}
