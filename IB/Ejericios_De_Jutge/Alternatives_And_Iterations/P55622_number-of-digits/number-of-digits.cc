#include <iostream>

int main() {
  int numero{};
  std::cin >> numero;
  if (numero < 0) {
    std::cerr << "este no es un numero valido" << '\n';
    return 1;
  } else if (numero == 0){
      std::cout << "The number of digits of 0 is 1." << '\n';
  } else {
      int contador_digitos{};
      int numero_absoluto{numero};
      while (numero_absoluto > 0) {
        numero_absoluto /= 10;
        ++contador_digitos;
      }
  std::cout << "The number of digits of " << numero << " is " << contador_digitos << "." << '\n';
  }
  return 0;
}         
