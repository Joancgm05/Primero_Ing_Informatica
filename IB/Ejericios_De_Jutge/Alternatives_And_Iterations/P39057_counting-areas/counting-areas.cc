#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

int main() {
  int numero_de_figuras {};
  std::cin >> numero_de_figuras;
  if (numero_de_figuras == 0) {
    return 0;
  }
  std::string figura;
  double largo{}, alto{}, radio{};
  const double knumero_pi = M_PI;

  for (int i = 0; i < numero_de_figuras; ++i) {
    std::cin >> figura;
    if (figura == "rectangle") {
      std::cin >> largo >> alto;
      std::cout << std::fixed << std::setprecision(6) << largo * alto << '\n';
    }
    else if (figura == "circle") {
      std::cin >> radio;
      std::cout << std::fixed << radio * radio * knumero_pi<< '\n';
    }
  }
  return 0;
}
