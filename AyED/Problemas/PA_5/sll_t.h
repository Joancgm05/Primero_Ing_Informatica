// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef SLLT_H_
#define SLLT_H_

#include <iostream>
#include <cassert>

#include "sll_node_t.h"

// Clase para almacenar una lista simplemente enlazada
template <class T> 
class sll_t {
 public:
  // constructor
  sll_t(void) : head_(NULL) {}

  // destructor
  ~sll_t(void);

  // getters
  sll_node_t<T>* get_head(void) const { return head_; }; // metodo para obtener el primer nodo de la lista
  
  bool empty(void) const; // metodo para comprobar si la lista esta vacia

  // operaciones
  void push_front(sll_node_t<T>*); // metodo para insertar un nodo al principio de la lista
  sll_node_t<T>* pop_front(void); // metodo para eliminar el primer nodo de la lista

  void insert_after(sll_node_t<T>*, sll_node_t<T>*); // metodo para insertar un nodo despues de otro nodo
  sll_node_t<T>* erase_after(sll_node_t<T>*); // metodo para eliminar un nodo despues de otro nodo

  sll_node_t<T>* search(const T&) const; // metodo para buscar un nodo en la lista

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

  // Problemas
  T remove_last(void);
  void swap12(void);
  void duplicate(void);
  void erase_evens(void);
  sll_t<T> move_odds(void);

 private:
  sll_node_t<T>* head_;
};


// destructor
template <class T> sll_t<T>::~sll_t(void) {
  while (!empty()) {
    sll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
}

// Comprobar si lista vacía
template <class T> bool sll_t<T>::empty(void) const {
  return head_ == NULL;
}

// operaciones
template <class T> void sll_t<T>::push_front(sll_node_t<T>* n) {
  assert(n != NULL);

  n->set_next(head_);
  head_ = n;
}

template <class T> sll_node_t<T>* sll_t<T>::pop_front(void) { 
  assert(!empty());
  sll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  aux->set_next(NULL);

  return aux;
}

template <class T> void sll_t<T>::insert_after(sll_node_t<T>* prev,
					       sll_node_t<T>* n) {
  assert(prev != NULL && n != NULL);

  n->set_next(prev->get_next());
  prev->set_next(n);
}

template <class T> sll_node_t<T>* sll_t<T>::erase_after(sll_node_t<T>* prev) { 
  assert(!empty());
  assert(prev != NULL);
  sll_node_t<T>* aux = prev->get_next();
  
  assert(aux != NULL);
  prev->set_next(aux->get_next());
  aux->set_next(NULL);

  return aux;
}

template <class T> sll_node_t<T>* sll_t<T>::search(const T& d) const {
  sll_node_t<T>* aux = head_;
  while ((aux != NULL) && (aux->get_data() != d))
    aux = aux->get_next();
    
  return aux;
}

// E/S
template <class T> std::ostream& sll_t<T>::write(std::ostream& os) const {
  sll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

// Problemas
// Eliminar y liberar el último elemento de una lista, devolviendo el dato
template <class T> T sll_t<T>::remove_last(void) {
  assert(!empty());
  sll_node_t<T>* aux = get_head();
  sll_node_t<T>* prev = NULL;
  while (aux->get_next() != NULL) {  // Recorrer hasta que aux apunte al último
    prev = aux;
    aux = aux->get_next();
  }
  sll_node_t<T>* node;
  if (prev == NULL)  // Sí último es primero usar pop_front, sino erase_after
    node = pop_front(); 
  else
    node = erase_after(prev);
  T dato = node->get_data();
  delete node;  // Liberar el nodo
  
  return dato;  // Devolver el dato
}

// Intercambiar el orden del elemento primero y segundo de una lista
template <class T> void sll_t<T>::swap12(void) {
  assert(!empty());
  assert(get_head()->get_next() != NULL);
  // Sacar el segundo y meterlo por la cabecera
  push_front(erase_after(get_head()));
}

// Duplicar todos los elementos de una lista insertardo las copias seguidas
// de los originales
template <class T> void sll_t<T>::duplicate(void) {
  sll_node_t<T>* aux = get_head();
  while (aux != NULL) {  // Recorrer toda la lista
    // Insertar un nodo después de aux duplicando sus campo dato
    insert_after(aux, new sll_node_t<T>(aux->get_data()));
    aux = aux->get_next()->get_next();  // Adelantar aux dos nodos
  }
}

// Eliminar y liberar todos los elementos de posiciones pares de una lista
template <class T> void sll_t<T>::erase_evens(void) {
  sll_node_t<T>* aux = get_head();
  while (aux != NULL && aux->get_next() != NULL) {  // Recorrer toda la lista
    delete erase_after(aux);  // Borrar el siguente a aux y liberarlo
    aux = aux->get_next();  // Solo adelantar aux un nodo, par ya borrado
  }
}

// Eliminar los nodos de posiciones impares de una lista trasladándolos
// en orden inverso a una nueva lista
template <class T> sll_t<T> sll_t<T>::move_odds(void) {
  sll_t<T> odds_list;  
  if (!empty())
    odds_list.push_front(pop_front());  // Mover primer nodo a lista impares
  sll_node_t<T>* aux = get_head();
  while (aux != NULL && aux->get_next() != NULL) {  // Recorrer toda la lista
    odds_list.push_front(erase_after(aux));  // Mover el siguiente a aux
    aux = aux->get_next();  // Solo adelantar aux un nodo, impar ya movido
  }
  return odds_list;  // Retornar lista de impares
}

#endif  // SLLT_H_
