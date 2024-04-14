// Dado un vector identifique los elementos múltiplos de 3.

#include <iostream>

using namespace std;

int main() {
  int n{10};
  int A[n] = {5, 3, 2, 1, 5, 1, 4, 2, 1, 6};
  int multiplo = 0, nomultiplo = 0;
  for (int i = 0; i < n; i++)
    if (A[i] % 3 == 0) {
      multiplo++;
  }
  else {
    nomultiplo++;
  }
  cout << "Multiplos de 3: " << multiplo << '\n';
  return 0;
}

