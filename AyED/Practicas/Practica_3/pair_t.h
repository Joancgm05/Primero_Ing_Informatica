// AUTOR: Joan Carlos García Méndez 
// FECHA: 13/03/2024
// EMAIL: alu0101656571@ull.edu.es 
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {
 public:
  // constructores
  pair_t(void); // constructor por defecto 
  pair_t(T, int); // constructor parametrizado

  // destructor
  ~pair_t(void); // destructor de la clase

  // getters & setters
  T get_val(void) const; // devuelve el valor
  int get_inx(void) const; // devuelve el índice
  void set(T, int); // asigna el valor y el índice

  // E/S
  std::istream& read(std::istream& is = std::cin); // lee el par desde un flujo de entrada
  std::ostream& write(std::ostream& os = std::cout) const; // escribe el par en un flujo de salida

 private:
  T val_; // valor
  int inx_; // índice
};


template<class T> 
pair_t<T>::pair_t() : val_(), inx_(-1) {} // constructor por defecto

template<class T> 
pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {} // constructor parametrizado

template<class T> 
pair_t<T>::~pair_t() {} // destructor de la clase

template<class T> 
void pair_t<T>::set(T val, int inx) { // asigna el valor y el índice
  val_ = val; // asigna el valor
  inx_ = inx; // asigna el índice
}

template<class T> 
int pair_t<T>::get_inx() const { // devuelve el índice
  return inx_; // devuelve el índice
}

template<class T>
 T pair_t<T>::get_val() const { // devuelve el valor
  return val_; // devuelve el valor
}

template<class T> 
std::istream& pair_t<T>::read(std::istream& is) { // lee el par desde un flujo de entrada
  return is >> inx_ >> val_; // lee el índice y el valor
}

template<class T> 
std::ostream& pair_t<T>::write(std::ostream& os) const { // escribe el par en un flujo de salida
  return os << "(" << inx_ << ":" << val_ << ")"; // escribe el índice y el valor
}

template<class T> 
std::ostream& operator<<(std::ostream& os, const pair_t<T>& p) { // sobrecarga del operador de salida
  p.write(os); // escribe el par en un flujo de salida
  return os; // devuelve el flujo de salida
}

#endif  // PAIRT_H_
