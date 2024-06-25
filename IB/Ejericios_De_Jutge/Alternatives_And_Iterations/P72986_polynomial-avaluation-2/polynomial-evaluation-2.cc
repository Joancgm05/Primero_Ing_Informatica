#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

int main() {
  double numero{}, numerosdelafuncion{}, total{};
  int elevadoan{};
  std::cin >> numero;
  std::vector<double> funcion;
  while (std::cin >> numerosdelafuncion){
    funcion.emplace_back(numerosdelafuncion);
    ++elevadoan;
  }
  for (int i = 0; i < elevadoan; ++i){
    total += funcion[i] * pow(numero, elevadoan - i - 1);
  }
  std::cout << std::fixed << std::setprecision(4) << total << '\n';
  return 0;
}
