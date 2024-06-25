#include <iostream>
#include <sstream>

int main() {
  int numero_natural;
  std::cin >> numero_natural;
  std::ostringstream hexadecimalStream;
  if (numero_natural == 0) {
    std::cout << "0" << '\n';
    return 0;
  }
  while (numero_natural > 0) {
    int digitoHex = numero_natural % 16;

    if (digitoHex < 10) {
      hexadecimalStream << digitoHex;
    } else {
        hexadecimalStream << static_cast<char>('A' + (digitoHex - 10));
      }
  numero_natural /= 16;
  }

  std::string hexadecimal = hexadecimalStream.str();
  std::string hexadecimal_final{std::string(hexadecimal.begin(), hexadecimal.end())};
  std::cout << hexadecimal_final << '\n';

  return 0;
}

