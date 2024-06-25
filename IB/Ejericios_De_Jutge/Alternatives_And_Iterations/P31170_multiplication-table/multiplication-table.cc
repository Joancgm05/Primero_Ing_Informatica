#include <iostream>

int main() {
  int numero{};
  std::cin >> numero;
  if (numero < 0 || numero > 9) {
    std::cerr << "este no es un número válido" << '\n';
    return 1;
  } else {
      for (int i{1}; i <= 10; ++i) {
        std::cout << numero << "*" << i << " = " << numero * i << '\n';
      }
    }
  return 0;
}
