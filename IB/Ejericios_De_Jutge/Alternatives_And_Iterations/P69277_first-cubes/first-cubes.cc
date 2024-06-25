#include <iostream>

int main() {
  int numero;
  std::cin >> numero;
  if (numero < 0) {
    std::cerr << "este número no es válido" << '\n';
    return 1;
  } else {
      for (int i{0}; i <= numero; ++i) {
        if (i == numero) {
          std::cout << i * i * i;
        }
        else {
        std::cout << i * i * i << ",";
        }
      }
  std::cout << '\n';
  }
  return 0;
}
