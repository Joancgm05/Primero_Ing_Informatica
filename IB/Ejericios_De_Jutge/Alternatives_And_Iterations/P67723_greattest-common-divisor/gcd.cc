#include <iostream>
#include <algorithm>

int main() {
  int numero_uno, numero_dos;
  std::cin >> numero_uno >> numero_dos;
  std::cout << "The gcd of " << numero_uno << " and " << numero_dos 
            << " is " << std:: __gcd(numero_uno, numero_dos) << "." << '\n';
  return 0;
}
