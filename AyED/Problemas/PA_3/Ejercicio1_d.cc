//Cálculo el módulo del vector de los elementos
//nomultiplos.
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  const int n{10};
  int A[n] = {5, 3, 2, 1, 5, 1, 4, 2, 1, 6};

  int multiplo = 0, nomultiplo = 0;
  int* T = new int[n];
  int* N = new int[n];
  float sumatoria{0.0};

  for (int i = 0; i < n; i++) {
    if (i % 3 == 0) {
    T[multiplo++] = i;
    }
    else {
      N[nomultiplo++] = A[i];
      sumatoria += A[i];
    }
  }

  cout << "El módulo del Vector es : " <<
  sqrt(sumatoria) << endl;
  delete[] T, N;
}
