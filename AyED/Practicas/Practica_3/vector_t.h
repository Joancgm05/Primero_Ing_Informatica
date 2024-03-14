// AUTOR: Joan Carlos García Méndez 
// FECHA: 13/03/2024
// EMAIL: alu0101656571@ull.edu.es
// VERSION: 3.1
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef VECTORT_H_
#define VECTORT_H_

#include <iostream>
#include <cassert>

template<class T> 
class vector_t {
 public:
  // constructores
  vector_t(const int = 0); // constructor normal
  vector_t(const vector_t&); // constructor de copia

  // operador de asignación
  vector_t<T>& operator=(const vector_t<T>&); // operador de asignación

  // destructor
  ~vector_t(); // destructor de la clase
  
  // getters
  T get_val(const int) const; // devuelve el valor de la posición i
  int get_size(void) const; // devuelve el tamaño del vector
  
  // setters
  void set_val(const int, const T); // asigna el valor d a la posición i
  
  // getters-setters
  T& at(const int); // devuelve la referencia al valor de la posición i
  T& operator[](const int); // devuelve la referencia al valor de la posición i
  
  // getters constantes
  const T& at(const int) const; // devuelve la referencia constante al valor de la posición i
  const T& operator[](const int) const; // devuelve la referencia constante al valor de la posición i

  // Redimensionado
  void resize(const int); // redimensiona el vector
  
  // E/S
  void read(std::istream& = std::cin); // lee el vector desde un flujo de entrada
  void write(std::ostream& = std::cout) const; // escribe el vector en un flujo de salida

 private: 
  T* v_; // vector
  int sz_; // tamaño del vector
  
  void build(void); // construye el vector
  void destroy(void); // destruye el vector
};


template<class T> 
vector_t<T>::vector_t(const int n) : v_(NULL), sz_(n) { // constructor normal
  build(); // construye el vector
}

// constructor de copia
template<class T> 
vector_t<T>::vector_t(const vector_t<T>& w) : v_(NULL), sz_(0) { // constructor de copia
  *this = w; // se invoca directamente al operator=
}

// operador de asignación
template<class T> 
vector_t<T>& vector_t<T>::operator=(const vector_t<T>& w) { // operador de asignación
  resize(w.get_size()); // redimensiona el vector
  for (int i = 0; i < get_size(); i++) // copia los valores
    at(i) = w.at(i); // copia los valores
  
  return *this; // devuelve el vector
}

template<class T> 
vector_t<T>::~vector_t() { // destructor de la clase
  destroy(); // destruye el vector
}

template<class T> 
void vector_t<T>::build() { // construye el vector
  v_ = NULL; // inicializa el vector
  if (sz_ != 0) { // si el tamaño del vector es distinto de 0
    v_ = new T[sz_]; // reserva memoria para el vector
    assert(v_ != NULL); // comprueba que la reserva de memoria se ha realizado correctamente
  }
}

template<class T> 
void vector_t<T>::destroy() { // destruye el vector
  if (v_ != NULL) { // si el vector no es nulo
    delete[] v_; // libera la memoria
    v_ = NULL; // el vector se inicializa a nulo
  }
  sz_ = 0; // el tamaño del vector se inicializa a 0
}

template<class T> 
void vector_t<T>::resize(const int n) { //redimensiona el vector
  destroy(); // destruye el vector
  sz_ = n; // el tamaño del vector se redimensiona
  build(); // construye el vector
}

template<class T> 
inline T vector_t<T>::get_val(const int i) const { // devuelve el valor de la posición i
  assert(i >= 0 && i < get_size()); // comprueba que la posición i es válida
  return v_[i]; // devuelve el valor de la posición i
}

template<class T> 
inline int vector_t<T>::get_size() const { // devuelve el tamaño del vector
  return sz_; // devuelve el tamaño del vector
}

template<class T> 
void vector_t<T>::set_val(const int i, const T d) { // asigna el valor d a la posición i
  assert(i >= 0 && i < get_size()); // comprueba que la posición i es válida
  v_[i] = d; // asigna el valor d a la posición i
}

template<class T> 
T& vector_t<T>::at(const int i) { // devuelve la referencia al valor de la posición i
  assert(i >= 0 && i < get_size()); // comprueba que la posición i es válida
  return v_[i]; // devuelve la referencia al valor de la posición i
}

template<class T> 
T& vector_t<T>::operator[](const int i) { // devuelve la referencia al valor de la posición i
  return at(i); // devuelve la referencia al valor de la posición i
}

template<class T> 
const T& vector_t<T>::at(const int i) const { // devuelve la referencia constante al valor de la posición i
  assert(i >= 0 && i < get_size()); // comprueba que la posición i es válida
  return v_[i]; // devuelve la referencia constante al valor de la posición i
}

template<class T> 
const T& vector_t<T>::operator[](const int i) const { // devuelve la referencia constante al valor de la posición i
  return at(i); // devuelve la referencia constante al valor de la posición i
}

template<class T> 
void vector_t<T>::read(std::istream& is) { // lee el vetor dede un flujo de entrada is
  is >> sz_; // lee el tamaño del vector
  resize(sz_); // redimensiona el vector
  for (int i = 0; i < sz_; i++) // lee los valores del vector
    is >> at(i); // lee los valores del vector
}

template<class T> 
void vector_t<T>::write(std::ostream& os) const { // escribe el vector en un flujo de salida os
  os << get_size() << ": [ "; // escribe el tamaño del vector
  for (int i = 0; i < get_size(); i++) // escribe los valores del vector
    os << at(i) << (i != get_size() - 1 ? "\t" : ""); // escribe los valores del vector
  os << " ]" << std::endl; // escribe el final del vector
}

template<class T> 
std::istream& operator>>(std::istream& is, vector_t<T>& v) { // sobrecarga del operador >>
  v.read(is); // lee el vector desde un flujo de entrada
  return is; // devuelve el flujo de entrada
}

template<class T> 
std::ostream& operator<<(std::ostream& os, const vector_t<T>& v) { // sobrecarga del operador <<
  v.write(os); // escribe el vector en un flujo de salida
  return os; // devuelve el flujo de salida
}

#endif  // VECTORT_H_
