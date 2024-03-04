// Inserte en un vector dinámico el índice de los múltiplos 
// de 3 y en un segundo vector dinámico el valor de los no 
// múltiplos de 3.
#include <iostream>

using namespace std;

int main() {
  int n{10};
  int A[n] = {5, 3, 2, 1, 5, 1, 4, 2, 1, 6};
  int multiplo = 0, nomultiplo = 0;
  int* T = new int[n];
  int* N = new int[n];
  for (int i = 0; i < n; i++)
    if (A[i] % 3 == 0) {
      T[multiplo] = i;
      multiplo++;
    }
    else {
      N[nomultiplo] = A[i];
      nomultiplo++;
    }
  cout << "Multiplos de 3: " << multiplo << endl;

  for (int i = 1; i <= multiplo; i++)
    cout << T[i] << " ";
    delete[] T, N;

  return 0;
}
