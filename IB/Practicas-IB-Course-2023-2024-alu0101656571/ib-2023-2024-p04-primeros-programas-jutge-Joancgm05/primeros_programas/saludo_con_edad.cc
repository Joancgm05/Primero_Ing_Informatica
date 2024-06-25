/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
  * @date Oct 8 2023
  * @brief The program asks your name and your age and then
  *        prints those two elements in the terminal
  *
  * @bug There are no known bugs
  */

#include <iostream>
#include <string>

int main() {
  std::string nombre;
  int edad;
  std::cout << "Escribe tu nombre. " << std::endl;
  std::cin >> nombre;
  std::cout << "Escribe tu edad. " << std::endl;
  std::cin >> edad;
  std::cout << "Hola, eres " << nombre
	    << " y tienes " << edad << " años." << std::endl;  
  
  return 0;
}
