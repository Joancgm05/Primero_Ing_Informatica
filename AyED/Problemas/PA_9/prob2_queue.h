// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 6
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Librería con problemas resueltos 2
// COMPILACIÓN: g++ -g main_queue_prob2.cc -o main_queue_prob2
// EJECUCIÓN: ./main_queue_prob2

#include "queue_v_t.h"
#include "queue_l_t.h"
#include "stack_l_t.h"

// Invertir el orden de los elementos de una cola, usando
// si es necesario una estructura auxiliar de otro tipo.

template <template<class> class Q, class T> void reverse(Q<T> &src) {
  // La clase Q que contiene datos de tipo T
  stack_l_t<T> aux;  // Se usa una pila auxiliar para invertir el orden
  while (!src.empty()) {
    aux.push(src.front());  // Se vuelca todo el contenido a la pila
    src.pop();
  }
  while (!aux.empty()) {
    src.push(aux.top());  // Se devuelven todos los elementos a la cola
    aux.pop();
  }
}

// A partir de una cola eliminar de ella todos los elementos de
// posiciones impares. Considere el elemento en el final de la cola impar

template <class Q> void remove_odds(Q &src) {
  int size = src.size();  // Recordamos el tamaño inicial
  for (int i = 0; i < size; i++) {
    if ((size - i) % 2 == 0)  // El final de la cola es impar (i = size - 1)
      src.push(src.front());  // Los elementos pares se vuelcan en la cola original
    src.pop();
  }
}

template <class Q> void remove_odds2(Q &src) {
  int size = src.size();  // Recordamos el tamaño inicial
  for (int i = size; i > 0; i--) {
    if (i % 2 == 0)  // El final de la cola es impar
      src.push(src.front());  // Los elementos pares se vuelcan en la cola original
    src.pop();
  }
}
// Fusionar dos colas en una tercera, tomando elementos alternativamente
// de una y de otra. Si tienen distintos tamaños, los elementos sobrantes
// se introducen igualmente. Las colas originales quedan vacías

template <class Q> Q fuse(Q &a, Q &b) {
  Q ab;
  while (!a.empty() || !b.empty()) {
    if (!a.empty()) {
      ab.push(a.front());
      a.pop();
    }
    if (!b.empty()) {
      ab.push(b.front());
      b.pop();
    }
  }
  return ab;
}

template <class Q> Q fuse2(Q &a, Q &b) {
  Q ab;
  while (!a.empty() && !b.empty()) {
    ab.push(a.front());
    a.pop();
    ab.push(b.front());
    b.pop();
  }
  while (!a.empty()) {
    ab.push(a.front());
    a.pop();
  }
  while (!b.empty()) {
    ab.push(b.front());
    b.pop();
  }
  return ab;
}

// Eliminar los elementos repetidos de una cola, usando si es necesario
// una estructura auxiliar de otro tipo

template <template<class> class Q, class T> void remove_repeated(Q<T> &src) {
  // La clase cola Q contiene datos de tipo T
  int size = src.size();  // Tamaño original de la cola
  int n = 0;  // Número de elementos no repetidos encontrados hasta el momento
  T *aux = new T[size];  // Estructura auxiliar
  for (int i = 0; i < size; i++) { // Para cada elemento de la cola
    bool found = false;  // Comprobamos si ya aparece en la estructura auxiliar
    for (int j = 0; j < n && !found; j++)
      if (aux[j] == src.front())
        found = true;
    if (!found) {  // Si no está repetido, lo añadimos tanto a la cola como a aux
      aux[n++] = src.front();
      src.push(src.front());
    }
    src.pop();
  }
  delete[] aux;
}
