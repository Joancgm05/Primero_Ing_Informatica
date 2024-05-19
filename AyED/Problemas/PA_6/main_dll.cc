// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 
// COMPILACIÓN: g++ -g main_dll.cc -o main_dll
// EJECUCIÓN: ./main_dll

#include <iostream>

#include "dll_t.h"

using namespace std;

int main(void) {
  const int n_chars{26};
  dll_t<char> lista;

  // Inserción de n_chars elementos ('a', 'b, 'c' ...) a la lista por el frente
  for (int i = 0; i < n_chars; i++) {
    cout << "Introduciendo la letra: " << (char)('a' + i) << endl;
    lista.push_front(new dll_node_t<char>('a' + i));
    // Impresión de la lista elemento a elemento
    lista.write();
    cout << endl;
  }

  // Extracción del elemento 1 por el frente
  dll_node_t<char>* nodo = lista.pop_front();
  char dato = nodo->get_data();
  delete nodo;

  // Impresión del elemento 1 extraído
  cout << "Extrae desde cabecera: " << dato << endl;

  // Extracción de elemento 2 por el frente
  nodo = lista.pop_front();
  dato = nodo->get_data();
  delete nodo;

  // Impresión del elemento 2 extraído
  cout << "Extrae desde cabecera: " << dato << endl;

  // Extracción de elemento por la cola
  nodo = lista.pop_back();
  dato = nodo->get_data();
  delete nodo;

  // Impresión del elemento extraído por la cola
  cout << "Extrae desde cola: " << dato << endl;

  // Impresión de la lista elemento a elemento
  lista.write();
  cout << endl;

  // Borrado de elemento tercero por el frente
  nodo = lista.erase(lista.get_head()->get_next()->get_next());
  dato = nodo->get_data();
  delete nodo;
  cout << "Borra tercer elemento desde frente: " << dato << endl;
  
  // Impresión de la lista elemento a elemento
  lista.write();
  cout << endl;

  // Extracción de elemento por la cola
  nodo = lista.pop_back();
  dato = nodo->get_data();
  delete nodo;

  cout << "Extrae desde cola: " << dato << endl;

  // Impresión de la lista elemento a elemento
  lista.write();
  cout << endl;

  // Obtención del nodo de la cola
  nodo = lista.get_tail();
  dato = nodo->get_data();

  cout << "Dato en la cola: " << dato << endl;

  // Impresión de la lista elemento a elemento
  lista.write();
  cout << endl;

  // PROBLEMAS
  // Insertar un nodo después de otro pasado por parámetro
  lista.insert_after(lista.get_head(), new dll_node_t<char>('|'));
  cout << "Inserta en segunda posición el caracter '|'" << endl;
  
  // Impresión de la lista elemento a elemento
  lista.write();
  cout << endl;

  lista.insert_after(lista.get_tail(), new dll_node_t<char>('/'));
  cout << "Inserta en la última posición el caracter '/'" << endl;

  // Impresión de la lista elemento a elemento
  lista.write();
  cout << endl;

  // Intercambiar el orden del elemento último y penúltimo de una lista
  lista.swap_lasts();
  cout << "Intercambiado el orden entre último y penúltimo" << endl;

  // Impresión de la lista elemento a elemento
  lista.write();
  cout << endl;

  // Duplicar todos los elementos de una lista insertando todas las
  // copias seguidas al final de la lista original
  lista.duplicate_end();
  cout << "Duplicado elementos de lista y puestos al final" << endl;

  // Impresión de la lista elemento a elemento
  lista.write();
  cout << endl;

  // Eliminar y liberar todos los elementos de posiciones impares de una lista
  lista.erase_odds();
  cout << "Eliminados y liberados elementos de posiciones impares" << endl;

  // Impresión de la lista elemento a elemento
  lista.write();
  cout << endl;

  // Eliminar y liberar todos los elementos de posiciones impares de una lista
  lista.erase_odds();
  cout << "Nuevamente eliminados y liberados elementos de posiciones impares" << endl;

  // Impresión de la lista elemento a elemento
  lista.write();
  cout << endl;
  
  // Eliminar los nodos de posiciones pares de una lista trasladándolos en
  // el mismo orden a una nueva lista
  dll_t<char> lista_pares = lista.move_evens();
  cout << "Movidos elementos de posiciones pares a lista de pares" << endl;
  cout << "lista de pares: ";
  lista_pares.write(cout);
  cout << endl;
  cout << "lista original: ";
  lista.write(cout);
  cout << endl;

  dll_t<char> lista_pares2 = lista.move_evens();
  cout << "Movidos nuevamente elementos de posiciones pares a lista de pares 2";
  cout << endl;
  cout << "lista de pares2: ";
  lista_pares2.write(cout);
  cout << endl;
  cout << "lista original: ";
  lista.write(cout);
  cout << endl;
  
  return 0;
}
