#include <iostream>

int main() {
  double a{1.0};
  double b{1.0};
  const double c{a - b};
  if (c == 0) {
    std::cout << "cero" << '\n';
  }
  return 0;
}