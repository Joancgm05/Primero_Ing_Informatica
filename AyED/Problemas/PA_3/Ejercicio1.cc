#include <iostream>

using namespace std;

int main() {
  const int n{10};
  int A[n] = {5, 3, 2, 1, 5, 1, 4, 2, 1, 6};
  int multiplo = 0, nomultiplo = 0;
  int multiplos_suma{0}, nomultiplos_suma{0};

  int* T = new int[n];
  int* N = new int[n];
  
  for (int i = 0; i < n; i++)
    if (A[i] % 3 == 0) {
      T[multiplo] = i;
      ++multiplo;
    }
    else {
      N[nomultiplo] = A[i];
      ++nomultiplo;
    }

  cout << "Multiplos de 3: " << multiplo << '\n';

  for (int i{1}; i <= multiplo; ++i) 
    cout << T[i] << " ";
  
  delete[] T, N;
}
