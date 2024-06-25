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
#include <vector>

bool is_increasing(int n) {
  std::vector<int> my_vector;
  for (int i{n}; i > 0; i /= 10) {
    my_vector.emplace_back(i);
    if (my_vector[i] > my_vector[i+1]) {
      return 1;
    } 
  }
  return 0;
}

int main() {
  int number;
  std::cin >> number;
  std::cout << is_increasing(number) << '\n';
  return 0;
}
