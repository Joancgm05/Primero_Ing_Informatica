#include <iostream>

using namespace std;

// Definicón de la clase
class complex_t {

public:
  complex_t(const double real = 0, const double imag = 0) : // Constructor parametrizado
real_(real), imag_(imag) {}
  ~complex_t() {} // Destructor por defecto

  // Getters
  double get_real() { return real_; } // Método para obtener la parte real
  double get_imag() { return imag_; } // Método para obtener la parte imaginaria 

  // Método que escrible el número complejo
  void write(void) {
  cout << "(" << real_ << ", " << imag_ << "i)" << endl; 
  }

  // Método que calcula la suma de números complejos
  complex_t add(const complex_t& other) {
  return complex_t(real_ + other.real_, imag_ + other.imag_);
}

private:
  double real_, imag_; // Atributos privados de la clase complex_t
};

// Programa principal
int main() {
  complex_t numero_complejo1(3.0, 4.0);
  complex_t numero_complejo2(1.0, 2.0);

  cout << "El primer número complejo es: ";
  numero_complejo1.write();

  cout << "El segundo número complejo es: ";
  numero_complejo2.write();

  cout << "La suma de los dos números complejos es: ";
  numero_complejo1.add(numero_complejo2).write();

  return 0;
}
