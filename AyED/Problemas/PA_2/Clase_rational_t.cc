#include <iostream>
#include <cassert>

using namespace std;

// Definición de la clase
class rational_t {

public:
  rational_t(const int n = 0, const int den = 1); // Constructor parametrizado
  ~rational_t(); // Destructor

  // Getters
  int get_n() const { return num; }
  int get_d() const { return den; }

  void write(void); // Escribe el racional

  rational_t add(const rational_t& r); // Método que suma dos racionales
  rational_t substract(const rational_t& r); // Método para restar dos racionales 
  rational_t multiply(const rational_t& r); // Método para multiplicar dos racionales 
  rational_t divide(const rational_t& r); // Método para dividir dos racionales 

private:
  int num, den; // Atributos privados de la clase rational_t
  int gcd(int a, int b);  // Función auxiliar para calcular el máximo común divisor (GCD)
  void simplify(); 
};

// Implementación de la clase:
rational_t::rational_t(const int n, const int d) {
  assert(d != 0); // Se comprueba que el denominador sea distinto de cero
  num = n,  den = d; // Asigna el numerador y el denominador 
  simplify();     
}

// Escribe el racional
void rational_t::write() {
cout << get_n() << "/" << get_d() << '\n'; 
}

// Implementación del método que suma dos racionales
rational_t rational_t::add(const rational_t& r) {
  int numerador{get_n() * r.get_d() + get_d() * r.get_n()}; // Se calcula el numerador de la suma de los dos racionales
  int denominador{get_d() * r.get_d()}; // Se calcula el denominador de la suma de los dos racionales
  return rational_t(numerador, denominador); // Se devuelve la suma del racional
}

// Implementación del método que resta dos racionales 
rational_t rational_t::substract(const  rational_t &r) {
  int numerador{(get_n() * r.get_d()) - (get_d() * r.get_n())}; // Se calcula  el numerador de la diferencia entre los dos racionales
  int denominador{get_d() * r.get_d()}; // Se calcula el denominador de la diferencia entre los dos racionales 
  return rational_t (numerador, denominador); // Se devuelve la diferencia de los racionales 
}

// Implementación del método que multiplica dos racionales 
rational_t rational_t::multiply(const rational_t &r) {
  int numerador{get_n() * r.get_n()}; // Se calcula el numerador del la multiplicación de los dos racionales 
  int denominador{get_d() * r.get_d()}; // Se Calcula el denominador de la multiplicación de los dos racionales
  return rational_t(numerador, denominador); // Se devuelbe la multiplicación de los racionales 
}

// Implementación del método que divide dos racionales
rational_t rational_t::divide(const rational_t &r) {
  int numerador{get_n() * r.get_d()};
  int denominador{get_d() * r.get_n()};
  return rational_t (numerador, denominador);
}

int rational_t::gcd(int a, int b) {
  if (b == 0)
    return a;
  else 
    return gcd(b, a % b);
}

void rational_t::simplify() {
  int mcd = gcd(num, den);
  num /= mcd;
  den /= mcd;

}

// Destructor por defecto de la clase rational_t
rational_t::~rational_t() {}

// Programa principal:
int main() {
  rational_t a(1, 2), b (2,3);

  cout << "La primera fracción es: ";
  a.write();
  
  cout << "La segunda fracción es: ";
  b.write();

  cout << "La suma de las dos fracciones es: ";
  a.add(b).write();

  cout << "La resta de las dos fracciones es: ";
  a.substract(b).write();

  cout << "La multiplicación de las dos fracciones es: ";
  a.multiply(b).write();

  cout << "La división de las dos fracciones es: ";
  a.divide(b).write();

  return 0;
}
