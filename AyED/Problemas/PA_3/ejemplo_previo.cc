#include <iostream>
#include <vector>

int main() {
  const int n{10};
  int A[n] = {5, 3, 2, 1, 5, 1, 4, 2, 1, 6};
  int pares = 0, impares = 0;

  for (int i{0}; i < n; ++i) {
    if (A[i] % 2 == 0) {
      ++pares;
    } else {
      ++impares;
    }
  }
  // Múltiplos de 3 e insertar en vector dinámico
  std::vector<int> multiplo;
  std::vector<int> nomultiplo;
  for (int i{0}; i < n; ++i) {
    if (A[i] % 3 == 0 ) {
        multiplo.emplace_back(i);
    } else {
        nomultiplo.emplace_back(A[i]);
    }
    std::cout << "Múltiplos de 3: " << multiplo[i] << '\n';
  }
  return 0;
}
