/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 20 nov 2023
 * @brief 
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>
#include <vector>

bool exists(int x, const std::vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    if (v[i] == x) {
      return true;
    }
  }
  return false;
}

int main() {
  int x{5};
  const std::vector<int> &v{5, 10};
  std::cout << exists(x, v) << '\n';
  return 0;
}
