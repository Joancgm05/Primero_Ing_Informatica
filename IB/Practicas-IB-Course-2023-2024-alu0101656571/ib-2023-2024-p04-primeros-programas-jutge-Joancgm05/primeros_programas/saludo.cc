/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
  * @date Oct 8 2023
  * @brief The program asks your name and then prints it in the 
  *        terminal with two sentences
  *
  * @bug There are no known bugs
  */


#include <iostream>
#include <string>

int main() {
  std::string nombre;
  std::cout << "Tu nombre? ";
  std::cin >> nombre;
  std::cout << "Muy buenas, " << nombre
	    << ", eres un gran programador." << std::endl;

  return 0;
}
