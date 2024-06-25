/* 
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Informática Básica 2023-2024
* @file 
* @author Joan Carlos García Méndez alu0101656571@ull.edu.es
* @date Mes Día Año
* @brief Descripción
* @bug Nº de bugs
* @see https:g/jutge.org/problems/
*/

#include<iostream>
#include<string>

int main() {

  int variable_number;
  double largo, alto;
  double radio;
  double pi {3.1415};
  std::string rectangulo {};
  std::string circulo {};
  std::cin >> variable_number;
  
  if ( variable_number == 2) {
  
  std::cin >> rectangulo >> largo >> alto;
  std::cin >> circulo >> radio;
  std::cout << largo * alto << '\n';
  std::cout << (pi * 2) * radio << '\n';
  }
  if (variable_number < 2 && rectangulo == "rectangle") {
  std::cin >> rectangulo >> largo >> alto;
  std::cout << largo * alto << '\n';
  }
  if (variable_number < 2 && circulo == "circle") {
  std::cin >> circulo >> radio;
  std::cout << (pi * 2) * radio << '\n';
  }
  
  return 0;
}
