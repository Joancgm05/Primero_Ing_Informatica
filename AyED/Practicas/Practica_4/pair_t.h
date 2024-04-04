// AUTOR: Joan Carlos Garcia Méndez 
// FECHA: 01/04/2024
// EMAIL: alu0101656571@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {
 public:
  // constructores
  pair_t(void); // constrcutor por defecto
  pair_t(T, int); // constructor de copia

  // destructor
  ~pair_t(void); // desteurctor de la clase

  // getters & setters
  T get_val(void) const; // obtiene el valor
  int get_inx(void) const; // obtiene el índice
  void set(T, int); // establece el valor y el índice

  // E/S
  std::istream& read(std::istream& is = std::cin); // método para leer
  std::ostream& write(std::ostream& os = std::cout) const; // método para escribir

 private:
  T val_; // valor
  int inx_; // índice
};


template<class T> pair_t<T>::pair_t() : val_(), inx_(-1) {} // constructor por defecto, inx = -1 porque trabajamos con vectores

template<class T> pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {} // constructor de copia

template<class T> pair_t<T>::~pair_t() {} // destructor de la clase

template<class T> void pair_t<T>::set(T val, int inx) { // establece el valor y el índice
  val_ = val; // establece el valor
  inx_ = inx; // establece el índice
}

template<class T> int pair_t<T>::get_inx() const { // obtiene el índice
  return inx_;
}

template<class T> T pair_t<T>::get_val() const { // obtiene el valor
  return val_;
}

template<class T> std::istream& pair_t<T>::read(std::istream& is) { // método para leer el valor y el índice 
  return is >> inx_ >> val_;
}

template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const { // método para escribir el valor y el índice
  return os << "(" << inx_ << ":" << val_ << ")";
}

template<class T> std::ostream& operator<<(std::ostream& os, const pair_t<T>& p) { // sobrecarga del operador de inserción, para escribir el valor del índice
  p.write(os);
  return os;
}

#endif PAIRT_H_
