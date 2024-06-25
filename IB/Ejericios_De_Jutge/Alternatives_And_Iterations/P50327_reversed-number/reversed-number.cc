#include <iostream>

int main() {
  int numero_a_invertir{};
  std::cin >> numero_a_invertir;
  if (numero_a_invertir < 0) {
    std::cerr << "este no es un número válido" << '\n';
    return 1;
  } else {
      std::string invertido{std::to_string(numero_a_invertir)};
      std::string numero_final(invertido.rbegin(), invertido.rend());
      std::cout << numero_final << '\n';
    }
  return 0;
}      
