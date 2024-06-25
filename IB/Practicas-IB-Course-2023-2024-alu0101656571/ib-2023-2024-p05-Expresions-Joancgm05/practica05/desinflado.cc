/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date oct 15th 2023
 * @brief This program reads an uppercase letter and prints its
 *        corresponding lowercase letter on the screen 
 * @bug 0 bugs
 */
 
#include <iostream>

int main() {
  char letra_mayuscula;
  std::cin >> letra_mayuscula;

  int letra_minuscula;
  letra_minuscula = static_cast<int>(letra_mayuscula) + 32;
  std::cout << static_cast<char>(letra_minuscula) << '\n';

return 0;
}
