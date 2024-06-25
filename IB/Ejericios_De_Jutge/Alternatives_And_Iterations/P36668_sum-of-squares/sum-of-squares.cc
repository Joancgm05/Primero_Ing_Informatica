#include <iostream>

int main() {
  int numero{};
  std::cin >> numero;
  if (numero < 0) {
    std::cerr << "este numero no es válido" << '\n';
    return 1;
  } else {
      int result{};
      for (int i{1}; i <= numero; ++i) {
        result += i * i;
      }
    std::cout << result << '\n';
    }
 return 0;
}
