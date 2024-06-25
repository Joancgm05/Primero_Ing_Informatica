/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 29 oct 2023
 * @brief this program prints in the screen the n first numbers 
          of the serie of fibonacci
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>

void Fibonacci(int user_number) {
    int cero {0}, uno{1}, next; 
    for (int i{1}; i <= user_number; i++) {
      std::cout << cero << " ";
      next = cero + uno; 
      cero = uno;
      uno = next;
    }
}

int main() {
  int user_number;
  std::cin >> user_number;
  Fibonacci(user_number); 
  std::cout << std::endl;
  return 0;
}
