#include <iostream>

using namespace std;

int main() {
  const int m = 3;
  int C[m][m] = {{ 5,  1,  3},
                 {-1,  8,  2},
                 {-3, -2,  5}};

  bool is_asym = true;
  for (int i = 1; is_asym && (i < m); i++) {
    for (int j = 0; is_asym && (j <= i - 1); j++) {
      if (C[i][j] != -C[j][i])
        is_asym = false;
    }
  }
  return is_asym;
} 
