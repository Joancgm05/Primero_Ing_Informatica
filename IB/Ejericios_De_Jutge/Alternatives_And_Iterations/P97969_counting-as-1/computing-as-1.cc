/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date
 * @brief
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */
 
#include <iostream>
#include <algorithm>
#include <string>

int contador(std::string frase, char letra_a) {
  return count(frase.begin(), frase.end(), letra_a); 
}

int main(){
  std::string imput;
  getline(std::cin, imput);
  std::cout << contador(imput, 'a') << '\n';
  return 0;
}
