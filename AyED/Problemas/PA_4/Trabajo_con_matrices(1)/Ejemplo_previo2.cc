// Programa que calcula la matriz triangukar inferior sin la diagonal principal
#include <iostream>

using namespace std;

int main() {
  const int m{3};
  int C[m][m] = {{5, 1, 3},
                 {1, 8, 2},
                 {3, 2, 5}};

  cout << "Elementos de la submatriz triangular inferior sin diagonal: " << endl;
  for (int i = 1; i < m; i++) {
    for (int j = 0; j <= i - 1; j++)
      cout << C[i][j] << " ";
    cout << endl;
}
  return 0;
}