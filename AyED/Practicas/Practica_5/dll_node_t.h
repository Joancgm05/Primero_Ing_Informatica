// AUTOR: Joan Carlos García Méndez
// FECHA: 19 - 04 - 2024
// EMAIL: alu 0101656571@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef DLL_NODET_H_
#define DLL_NODET_H_

#include <iostream>

// Clase para nodos de listas doblemente enlazadas
template <class T> class dll_node_t {
 public:
  // constructores
  dll_node_t() : prev_(NULL), data_(), next_(NULL) {}  // por defecto
  dll_node_t(const T& data) : prev_(NULL), data_(data), next_(NULL) {} // parametrizado

  // destructor
  ~dll_node_t(void) {} 

  // getters & setters
  dll_node_t<T>* get_next(void) const { return next_; } // devuelve el siguiente nodo de la lista doblemente enlazada
  void set_next(dll_node_t<T>* next) { next_ = next; } // establece el siguiente nodo de la lista doblemente enlazada
  
  dll_node_t<T>* get_prev(void) const { return prev_; } // devuelve el nodo anterior de la lista doblemente enlazada
  void set_prev(dll_node_t<T>* prev) { prev_ = prev; } // establece el nodo anterior de la lista doblemente enlazada
  
  const T& get_data(void) const { return data_; } // devuelve el dato del nodo de la lista doblemente enlazada
  void set_data(const T& data) { data_ = data; } // establece el dato del nodo de la lista doblemente enlazada

  // E/S
  std::ostream& write(std::ostream& = std::cout) const; // imprime el dato del nodo de la lista doblemente enlazada

 private:
  dll_node_t<T>* prev_; // nodo anterior de la lista doblemente enlazada
  T data_; // dato del nodo de la lista doblemente enlazada
  dll_node_t<T>* next_; // nodo siguiente de la lista doblemente enlazada
};

  
// E/S
template <class T> std::ostream& dll_node_t<T>::write(std::ostream& os) const { // imprime el dato del nodo de la lista doblemente enlazada
  os << data_;
  return os;
}

#endif  // DLL_NODET_H_

