// Ejemplo de un código con herencias de clases

#include <iostream>

class A {
  private: 
    int i;

  protected: 
    int j;

  public: 
    int getI() 
    { 
      return i; 
    }
};

class B: public A {
  private: 
    int k;

  public: 
    int getJ() 
    { 
      return j; 
    }
};

int main() {
  B x;
  std::cout << x.getI() << '\t';
  std::cout << x.getJ();
  return 0;
}