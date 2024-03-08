#include <iostream>
#include <vector>

std::vector<int> obtenerVectorCircular(const std::vector<int>& vectorOriginal) {
  std::vector<int> vectorCircular(vectorOriginal.size());
  
  for (int i = 0; i < vectorOriginal.size(); i++) {
    vectorCircular[(i + 1) % vectorOriginal.size()] = vectorOriginal[i];
  }
  
  return vectorCircular;
}

int main() {
  std::vector<int> vectorOriginal = {1, 2, 3, 4, 5};
  std::vector<int> vectorCircular = obtenerVectorCircular(vectorOriginal);
  
  for (int i = 0; i < vectorCircular.size(); i++) {
    std::cout << vectorCircular[i] << " ";
  }
  
  std::cout << std::endl;
  
  return 0;
}