#include <iostream>

using namespace std;

int main() {
  const int m{3};
  int C[m][m] = {{5, 1, 3},
                 {1, 8, 2},
                 {3, 2, 5}};

  cout << "Elementos de la submatriz triangular inferior: " << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= i; j++)
    cout << C[i][j] << " ";
 cout << endl;
  }

  return 0;
}