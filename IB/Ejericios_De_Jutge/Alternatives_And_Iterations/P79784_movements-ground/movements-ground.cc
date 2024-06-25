#include <iostream>
#include <string>
#include <algorithm>

int contador(std::string frase, char letra) {
  return count(frase.begin(), frase.end(), letra);
}

int main() {
  std::string imput;
  getline(std::cin, imput);
  int n, s, w, e;
  n = contador(imput, 'n');
  s = contador(imput, 's');
  w = contador(imput, 'w');
  e = contador(imput, 'e');

  std::cout << "(" << e - w << ", " <<  s - n << ")" << '\n';
  return 0;
}
