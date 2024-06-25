#include <iostream>

int main() {
  int numero{};
  std::cin >> numero;
  for (int i{0}; i <= numero; ++i) {
    std::cout << i << '\n';
  }
  return 0;
}

