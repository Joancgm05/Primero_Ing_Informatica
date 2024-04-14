// Realizar la suma de los elementos en posiciones
//multiplos/nomultiplos, comprobar también si el
//índice del elemento es par/impar.
#include <iostream>

using namespace std;

int main() {
  int n{10};
  int A[n] = {5, 3, 2, 1, 5, 1, 4, 2, 1, 6};
  int multiplo = 0, nomultiplo = 0;
  int multiplos_suma = 0, nomultiplos_suma = 0;
  int* T = new int[n];
  int* N = new int[n];
  for (int i = 0; i < n; i++) {
    if (i % 3 == 0) {
      multiplos_suma += A[i];
      T[multiplo++] = i;
    }
    else {
      nomultiplos_suma += A[i];
      N[nomultiplo++] = A[i];
    }
    if (i % 2 == 0)
      cout << "El índice " << i << " es par." << endl;
    else
      cout << "El índice " << i << " es impar." << endl;
 }

 delete[] T, N;
 
 return 0;
}
