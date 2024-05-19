// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 6
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Problemas resueltos 2
// COMPILACIÓN: g++ -g main_queue_prob2.cc -o main_queue_prob2
// EJECUCIÓN: ./main_queue_prob2

#include <iostream>

// #include "queue_v_t.h"
#include "queue_l_t.h"
#include "prob2_queue.h"

using namespace std;

int main(void) {
  // queue_v_t<char> cola_vector;
  queue_l_t<char> cola_lista_1, cola_lista_2, cola_lista_3;
  cout << "Llenar cola 1 elemento a elemento: " << endl;
  for (int i = 0; i < 8; i++)
    cola_lista_1.push('A' + i);
  cola_lista_1.write();

  cout << "Llenar cola 2 elemento a elemento: " << endl;
  for (int i = 0; i < 3; i++)
    cola_lista_2.push('X' + i);
  cola_lista_2.write();

  cout << "Llenar cola 3 elemento a elemento: " << endl;
  for (int i = 0; i < 4; i++)
    if (i % 2 == 0)
      cola_lista_3.push('X' + i);
    else
      cola_lista_3.push('A' + i);
  cola_lista_3.write();

  cout << "Invertir cola 1: " << endl;
  reverse(cola_lista_1);
  cola_lista_1.write();

  cout << "Eliminar impares cola 1: " << endl;
  remove_odds(cola_lista_1);
  cola_lista_1.write();

  cout << "Fusionar colas 1 y 2 en cola 4: " << endl;
  queue_l_t<char> cola_lista_4 = fuse(cola_lista_1, cola_lista_2);
  cola_lista_4.write();

  cout << "Fusionar colas 4 y 3 en cola 5: " << endl;
  queue_l_t<char> cola_lista_5 = fuse(cola_lista_4, cola_lista_3);
  cola_lista_5.write();

  cout << "Eliminar elementos repetidos en cola 5: " << endl;
  remove_repeated(cola_lista_5);
  cola_lista_5.write();

  return 0;
}
