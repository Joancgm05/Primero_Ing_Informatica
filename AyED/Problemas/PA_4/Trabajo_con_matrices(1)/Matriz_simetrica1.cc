#include <iostream>

using namespace std;

using namespace std;

int main() {
  const int m{3};
  int C[m][m] = {{5, 1, 3},
                 {1, 8, 2},
                 {3, 2, 5}};
   
   bool is_sym = true;
   for (int i{1}; i < m; ++i) {
      for (int j{0}; j <= i; ++j) {
        if (C[i][j] != C[j][i])
          is_sym = false;
      }
    }
    return is_sym;

  return 0;
}
    