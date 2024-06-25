#include <iostream>
#include <iomanip>

int main() {
  double numero{};
  double sumatoria{};
  int i {};
  while (std::cin >> numero){
    sumatoria += numero;
    ++i;
  }
  std::cout << std::fixed << std::setprecision(2) << sumatoria / i << '\n';
  return 0;
}
