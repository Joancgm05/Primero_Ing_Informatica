#include <iostream>
using namespace std;

int main() {
    const int m = 3, n = 4; int A[m][n] = { { 4, 5, 2, 9 }, 
                                            { 1, 7, 4, 2 }, 
                                            { 8, 6, 2, 0 } };
                                            
for (int i = 0; i < m; i++) { 
  for (int j = 0; j < n; j++){
    cout << A[i][j] << " "; 
  }
  cout << endl;
}

return 0;
}