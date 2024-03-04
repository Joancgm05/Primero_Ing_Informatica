int main() {
  const int n{10};
  int A[n] = {5, 3, 2, 1, 5, 1, 4, 2, 1, 6};
  int pares = 0, impares = 0;
  for (int i = 0; i < n; i++)
    if (A[i] % 2 == 0) {
      pares++;
    }
    else {
      impares++;
    }
}
