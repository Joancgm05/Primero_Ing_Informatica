// Programa que calcula si la matriz es simétrica
#include <iostream>

using namespace std;

int main() {
  const int m{3};
  int C[m][m] = {{5, 1, 3},
                 {1, 8, 2},
                 {3, 2, 5}};

  bool is_sym = true;
  int i = 1;
  while (is_sym && (i < m)) {
    int j = 0;
    while (is_sym && (j <= i - 1)) {
      if (C[i][j] != C[j][i])
        is_sym = false;
      j++;
    }
    i++;
  }
  return is_sym;
}
