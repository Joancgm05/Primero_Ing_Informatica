// AUTOR: Joan Carlos García Méndez
// FECHA: 19 - 04 - 2024
// EMAIL: alu 0101656571@ull.edu.es 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase TAD cola implementada con una lista

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cassert>

#include "dll_t.h"

// Clase TAD cola implementada con una lista
template <class T> class queue_l_t {
 private:
  dll_t<T>    l_; // lista doblemente enlazada

 public:
  // constructor
  queue_l_t(void) : l_() {}

  // destructor
  ~queue_l_t(void) {}

  // operaciones
  bool empty(void) const; // comprueba si la cola está vacía
  int size(void) const; // devuelve el tamaño de la cola
  void push(const T& dato); // añade un elemento a la cola
  void pop(void); // elimina un elemento de la cola
  const T& front(void) const; // devuelve el primer elemento de la cola
  const T& back(void) const; // devuelve el último elemento de la cola

  // E/S
  std::ostream& write(std::ostream& os = std::cout) const; // imprime la cola
};


// operaciones
template<class T> bool queue_l_t<T>::empty(void) const {
  return l_.empty();
}

template<class T> int queue_l_t<T>::size(void) const {
  return l_.get_size();	
}

template<class T> void queue_l_t<T>::push(const T& dato) {
  dll_node_t<T>* node = new dll_node_t<T>(dato); // Creamos un nodo con el dato
  assert(node != NULL);
  l_.push_front(node);
}

template<class T> void queue_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_back();
}

template<class T> const T& queue_l_t<T>::front(void) const {
  assert(!empty());
  return (l_.get_tail()->get_data());
}

template<class T> const T& queue_l_t<T>::back(void) const {
  assert(!empty());
  return (l_.get_head()->get_data());
}

 // E/S
template<class T> std::ostream& queue_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) {
    os << aux->get_data() << " ";
    aux = aux->get_next();
  }
  os << std::endl;
  return os;
}

template<class T> std::ostream& operator<<(std::ostream& os,
					   const queue_l_t<T>& q) {
  q.write(os);
  return os;
}


#endif  // QUEUE_H_
