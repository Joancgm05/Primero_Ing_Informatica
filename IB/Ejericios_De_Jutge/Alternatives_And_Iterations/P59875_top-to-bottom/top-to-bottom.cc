#include <iostream>

int main() {
  int numero_uno, numero_dos;
  std::cin >> numero_uno >> numero_dos;
  int start{std::max(numero_uno, numero_dos)};
  int end{std::min(numero_uno, numero_dos)};
  for (int i{start}; i >= end; --i) {
    std::cout << i << '\n';
  }
  return 0;
}
