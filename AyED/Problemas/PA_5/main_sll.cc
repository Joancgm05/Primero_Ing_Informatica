// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 
// COMPILACIÓN: g++ -g main_sll.cc -o main_sll
// EJECUCIÓN: ./main_sll

#include <iostream>

#include "sll_t.h"

using namespace std;

int main(void)
{
  const int n_chars{26};
  sll_t<char> lista;

  // Inserción de n_chars elementos ('a', 'b, 'c' ...) a la lista por el frente
  for (int i = 0; i < n_chars; i++)
    lista.push_front(new sll_node_t<char>('a' + i));

  // Impresión de la lista elemento a elemento
  lista.write(cout);
  cout << endl;

  // Extracción de elemento 1 por el frente
  sll_node_t<char>* nodo = lista.pop_front();
  char dato = nodo->get_data();
  delete nodo;

  // Impresión del elemento 1 extraído
  cout << "Dato 1: " << dato << endl;

  // Extracción de elemento 2 por el frente
  nodo = lista.pop_front();
  dato = nodo->get_data();
  delete nodo;

  // Impresión del elemento 2 extraído
  cout << "Dato 2: " << dato << endl;

  // Extracción de elemento 3 por el frente
  nodo = lista.pop_front();
  dato = nodo->get_data();
  delete nodo;

  // Impresión del elemento 3 extraído
  cout << "Dato 3: " << dato << endl;

  // Impresión de la lista elemento a elemento
  lista.write(cout);
  cout << endl;

  // Búsqueda e impresión del elemento 4 con valor 'n'
  nodo = lista.search('n');
  dato = nodo->get_data();
  cout << "Dato 4: " << dato << endl; 

  // Extracción del elemento siguiente al de valor 'n' localizado anteriormente
  nodo = lista.erase_after(nodo);
  dato = nodo->get_data();
  delete nodo;
  cout << "Se ha extraído la letra '" << dato << "'" << endl;

  // Impresión de la lista elemento a elemento
  lista.write(cout);
  cout << endl;

  // Eliminar y liberar el último elemento de una lista, devolviendo el dato
  dato = lista.remove_last();
  cout << "Se ha extraído la última letra '" << dato << "'" << endl;
  lista.write(cout);
  cout << endl;

  // Intercambiar el orden del elemento primero y segundo de una lista
  lista.swap12();
  cout << "Se ha intercambiado primero y segundo de la lista" << endl;
  lista.write(cout);
  cout << endl;

  // Duplicar todos los elementos de una lista insertardo las copias seguidas
  // de los originales
  lista.duplicate();
  cout << "Se han duplicado los elementos de la lista" << endl;
  lista.write(cout);
  cout << endl;

  // Eliminar y liberar todos los elementos de posiciones pares de una lista
  lista.erase_evens();
  cout << "Se han eliminado los elementos pares de la lista" << endl;
  lista.write(cout);
  cout << endl;
  lista.erase_evens();
  cout << "Se han vuelto a eliminar los elementos pares de la lista" << endl;
  lista.write(cout);
  cout << endl;

  // Eliminar los nodos de posiciones impares de una lista trasladándolos
  // en orden inverso a una nueva lista
  sll_t<char> lista_impares = lista.move_odds();
  cout << "Se han movido los elementos impares de la lista" << endl;
  cout << "lista de impares: ";
  lista_impares.write(cout);
  cout << endl;
  cout << "lista original: ";
  lista.write(cout);
  cout << endl;
  sll_t<char> lista_impares2 = lista_impares.move_odds();
  cout << "Se han movido los elementos impares de la lista de impares" << endl;
  cout << "lista de impares2: ";
  lista_impares2.write(cout);
  cout << endl;
  cout << "lista impares: ";
  lista_impares.write(cout);
  cout << endl;
  
  return 0;
}





