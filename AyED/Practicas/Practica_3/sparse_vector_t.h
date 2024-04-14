// AUTOR: Joan Carlos García Méndez 
// FECHA: 13/03/2024
// EMAIL: alu0101656571@ull.edu.es 
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <iostream> // cout, cin
#include <math.h>  // fabs

#include "vector_t.h" // clase para vectores
#include "pair_t.h" // clase para pares

#define EPS 1.0e-6 // un valor muy pequeño

typedef pair_t<double> pair_double_t; // par de doubles
typedef vector_t<pair_double_t> pair_vector_t; // vector de pares de doubles

class sparse_vector_t {
 public:
  // constructores
  sparse_vector_t(const int = 0); 
  sparse_vector_t(const vector_t<double>&, const double = EPS); // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia

  sparse_vector_t& operator=(const sparse_vector_t&); // operador de asignación

  ~sparse_vector_t(); // destructor de la clase
  
  // getters
  int get_nz(void) const; // devuelve el nº de valores distintos de cero
  int get_n(void) const; // devuelve el tamaño del vector

  // getters-setters
  pair_double_t& at(const int); // devuelve la referencia al par de la posición i
  pair_double_t& operator[](const int); // devuelve la referencia al par de la posición i
  
  // getters constantes
  const pair_double_t& at(const int) const; // devuelve la referencia constante al par de la posición i
  const pair_double_t& operator[](const int) const; // devuelve la referencia constante al par de la posición i

  // E/S
  void write(std::ostream& = std::cout) const; // escribe el vector en un flujo de salida

 private:
  pair_vector_t pv_;  // valores + índices
  int nz_;            // nº de valores distintos de cero = tamaño del vector
  int n_;             // tamaño del vector original

  // bool IsNotZero(const double, const double = EPS) const;
};


bool IsNotZero(const double val, const double eps = EPS) { // función auxiliar
  return fabs(val) > eps;
}

sparse_vector_t::sparse_vector_t(const int n) : pv_(n), nz_(0), n_(n) {} // constructor normal

// FASE II
sparse_vector_t::sparse_vector_t(const vector_t<double>& v, const double eps) : pv_(), nz_(0), n_(0) { // constructor normal
  n_ = v.get_size(); // tamaño del vector original
  for (int i = 0; i < n_; i++) { // recorremos el vector original
    if (v.at(i) != 0) { // si el valor es distinto de cero
      nz_++; // incrementamos el nº de valores distintos de cero
    }
  }
  pv_.resize(nz_); // redimensionamos el vector de pares

  for (int i{0}, p{0}; i < n_; i++) { // recorremos el vector original
    if (v.at(i) != 0) { // si el valor es distinto de cero
      pair_double_t aux(v.get_val(i), i); // creamos un par con el valor y el índice
      pv_.at(p) = aux; // asignamos el par al vector de pares
      ++p; // incrementamos el contador de pares
    }
  }
}

// constructor de copia
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w) { 
  *this = w;  // se invoca directamente al operator=
}

// operador de asignación
sparse_vector_t& sparse_vector_t::operator=(const sparse_vector_t& w) {
  nz_ = w.get_nz(); // se invoca directamente al getter
  n_ = w.get_n(); // se invoca directamente al getter
  pv_ = w.pv_; // se invoca directamente al operator=

  return *this; 
}

sparse_vector_t::~sparse_vector_t() {} // destructor de la clase

inline int sparse_vector_t::get_nz() const { // getter 
  return nz_; // devuelve el nº de valores distintos de cero
}

inline int sparse_vector_t::get_n() const { // getter
  return n_; // devuelve el tamaño del vector
}

pair_double_t& sparse_vector_t::at(const int i) { // getter-setter
  assert(i >= 0 && i < get_nz()); // comprueba que el índice está en el rango
  return pv_[i]; // devuelve la referencia al par de la posición i
}

pair_double_t& sparse_vector_t::operator[](const int i) { // sobrecarga del operador []
  return at(i); // devuelve la referencia al par de la posición i
}

const pair_double_t& sparse_vector_t::at(const int i) const { // getter constante
  assert(i >= 0 && i < get_nz()); // comprueba que el índice está en el rango
  return pv_[i]; // devuelve la referencia constante al par de la posición i
}

const pair_double_t& sparse_vector_t::operator[](const int i) const { // sobrecarga del operador [] constante
  return at(i); // devuelve la referencia constante al par de la posición i
}

// E/S
void sparse_vector_t::write(std::ostream& os) const { // escribe el vector en un flujo de salida
  os << get_n() << "(" << get_nz() << "): [ "; // escribe el tamaño del vector y el nº de valores distintos de cero
  for (int i = 0; i < get_nz(); i++) // recorremos el vector de pares
    os << pv_[i] << " "; // escribe el par
	os << "]" << std::endl; // escribe el par
}

std::ostream& operator<<(std::ostream& os, const sparse_vector_t& sv) {
  sv.write(os); // escribe el vector en un flujo de salida
  return os; // devuelve el flujo de salida
}

#endif  // SPARSE_VECTORT_H_
