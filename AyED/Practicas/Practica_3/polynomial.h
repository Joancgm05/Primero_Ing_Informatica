// AUTOR: Joan Carlos García Méndez 
// FECHA: 13/03/2024
// EMAIL: alu0101656571@ull.edu.es 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> { // hereda de vector_t
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {}; // constructor normal
  Polynomial(const Polynomial& pol) : vector_t<double>(pol) {}; // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const; // escribe el polinomio en un flujo de salida
  
  // operaciones
  double Eval(const double) const; // evalúa el polinomio en un punto
  bool IsEqual(const Polynomial&, const double = EPS) const; // compara si dos polinomios son iguales
 };


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {}; // constructor normal
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {}; // constructor de conversión
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const; // escribe el polinomio en un flujo de salida
  
  // operaciones
  double Eval(const double) const; // evalúa el polinomio en un punto
  bool IsEqual(const SparsePolynomial&, const double = EPS) const; // compara si dos polinomios son iguales
  bool IsEqual(const Polynomial&, const double = EPS) const; // compara si dos polinomios son iguales
};

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const { // escribe el polinomio en un flujo de salida
  os << get_size() << ": [ "; // escribe el tamaño del polinomio
  bool first{true}; // booleano para saber si es el primer elemento
  for (int i{0}; i < get_size(); i++) // recorre el polinomio
    if (IsNotZero(at(i), eps)) { // si el valor es distinto de cero
      os << (!first ? " + " : "") << at(i) // escribe el valor
	 << (i > 1 ? " x^" : (i == 1) ? " x" : ""); // escribe el índice
      if (i > 1) // si el índice es mayor que 1
	os << i; // escribe el índice
      first = false; // ya no es el primer elemento
    } 
  os << " ]" << std::endl; // escribe el final del polinomio
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) { // sobrecarga del operador de salida
  p.Write(os); // escribe el polinomio en un flujo de salida
  return os; // devuelve el flujo de salida
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  for (int i{0}; i < get_size(); i++) // recorre el polinomio
    result += at(i) * pow(x, i); // evalúa el polinomio en un punto (x^i * at(i)
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  // poner el código aquí
  // Comprobar si el tamaño de los vectores es igual
  if (get_size() != pol.get_size()) { return differents; }
  // Comprobar si los valores de los vectores son iguales
  for (int i{0}; i < get_size(); i++){
    if (fabs(get_val(i) - pol.get_val(i)) > eps) { return differents; }
  }
  return !differents;
}

// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const { // escribe el polinomio en un flujo de salida
  os << get_n() << "(" << get_nz() << "): [ "; // escribe el tamaño del polinomio y el nº de valores distintos de cero
  bool first{true}; // booleano para saber si es el primer elemento
  for (int i{0}; i < get_nz(); i++) { // recorre el polinomio
    int inx{at(i).get_inx()}; // obtiene el índice
    os << (!first ? " + " : "") << at(i).get_val() // escribe el valor
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : ""); // escribe el índice
    if (inx > 1) // si el índice es mayor que 1
      os << inx; // escribe el índice
    first = false; // ya no es el primer elemento
  }
  os << " ]" << std::endl; // escribe el final del polinomio
}

std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os); // escribe el polinomio en un flujo de salida
  return os; // devuelve el flujo de salida
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  for (int i{0}; i < get_nz(); i++) // recorre el polinomio
    result += at(i).get_val() * pow(x, at(i).get_inx()); // evalúa el polinomio en un punto (x^i * at(i)
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol, const double eps) const { 
  bool differents = false;
  // poner el código aquí
  int Tam_vec = 0;
  if (get_nz() != spol.get_nz()) { return differents; } // Comprobar si el tamaño de los vectores es igual
  for (int i{0}; i < get_nz(); i++){ // recorre el polinomio
    if (at(i).get_inx() != spol.at(i).get_inx()){ differents = true; } // Comprobar si el valor de los índices son iguales
    if (fabs(at(i).get_val() - spol.at(i).get_val()) >= eps){ differents = true; } // Comprobar si los valores son iguales
  }
  return !differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  // poner el código aquí
  return IsEqual(SparsePolynomial(pol));
}


#endif  // POLYNOMIAL_H_
