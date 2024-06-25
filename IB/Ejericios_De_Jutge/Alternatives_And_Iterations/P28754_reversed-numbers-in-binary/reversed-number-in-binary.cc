#include <iostream>
#include <string>

int main() {
  int numero_natural;
  std::cin >> numero_natural;
  std::string binario{};
  if (numero_natural == 0) {
    std::cout << "0" << '\n';
    return 0;
  }
  while (numero_natural != 0) {
    int bit{numero_natural % 2}; 
    binario = std::to_string(bit) + binario;
    numero_natural /= 2;
  }
  std::string numero_en_binario{std::string(binario.rbegin(), binario.rend())};
  std::cout << numero_en_binario << '\n';
  return 0;
}
