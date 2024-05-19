// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Problemas resueltos
// COMPILACIÓN: g++ -g main_stack_prob.cc -o main_stack_prob
// EJECUCIÓN: ./main_stack_prob

#include <iostream>

#include "stack_v_t.h"
#include "stack_l_t.h"

using namespace std;

int main(void) {
  stack_v_t<char> pila_vector;
  // stack_l_t<char> pila_lista;
  cout << "Llenar pila elemento a elemento: " << endl;
  for (int i = 0; i < 10; i++)
    pila_vector.push('a' + i);
  pila_vector.write();

  // Intercambiar el orden de los dos primeros elementos en el top de la pila
  cout << "Intercambiar orden de los dos primeros elementos: " << endl;
  char char1 = pila_vector.top();
  pila_vector.pop();
  char char2 = pila_vector.top();
  pila_vector.pop();
  pila_vector.push(char1);
  pila_vector.push(char2);
  pila_vector.write();

  // A partir de una pila generar otra con los elementos en orden inverso,
  // dejando la pila original vacía
  cout << "Generar nueva pila con elementos en orden inverso: " << endl;
  stack_v_t <char> pila_inv;
  while (!pila_vector.empty()) {
    pila_inv.push(pila_vector.top());
    pila_vector.pop();
  }
  pila_inv.write();

  // Eliminar todos los elementos de posiciones impares de una pila,
  // apoyándose en otra pila para ello. Considere el elemento en el fondo
  // de la pila impar
  cout << "Eliminar todos los elementos de posiciones impares de una pila: "
      << endl;
  stack_v_t <char> pila_aux;

  while (!pila_inv.empty()) {
    pila_aux.push(pila_inv.top());
    pila_inv.pop();
  }

  while (!pila_aux.empty()) {
    pila_aux.pop();
    if (!pila_aux.empty()) {
      pila_vector.push(pila_aux.top());
      pila_aux.pop();
    }
  }
  pila_vector.write();

  // A partir de una pila traslade sus elementos a dos pilas diferentes,
  // los que sean mayores que un valor dado a una y los restantes a otra,
  // dejando los elementos en las nuevas pilas en orden inverso al original
  char valor{'e'};
  cout << "Trasladar elementos mayores a valor '" <<  valor
       << "' a una pila y menores a otra: " << endl;
  stack_v_t <char> pila_mayor;
  stack_v_t <char> pila_menor;

  while (!pila_vector.empty()) {
    if (pila_vector.top() > valor)
      pila_mayor.push(pila_vector.top());
    else
      pila_menor.push(pila_vector.top());
    pila_vector.pop();
  }
  cout << "Pila mayor: " << endl;
  pila_mayor.write();
  cout << "Pila menor: " << endl;
  pila_menor.write();

  // Meter elementos de pila mayor en pila menor
  cout << "Meter elementos de pila mayor en pila menor: " << endl;
  while (!pila_mayor.empty()) {
    pila_menor.push(pila_mayor.top());
    pila_mayor.pop();
  }
  pila_menor.write();
  
  // Dada una pila obtener el máximo de sus elementos en base a ir
  // desapilando los dos primeros elementos en el top de la pila y
  // reemplazarlos por el máximo de ambos sucesivamente
  cout << "Obtener el máximo de los elementos desapilando dos a dos: " << endl;
  bool salir = false;
  while (!pila_menor.empty() && !salir) {
    char elem1 = pila_menor.top();
    pila_menor.pop();
    if (!pila_menor.empty()) {
      char elem2 = pila_menor.top();
      pila_menor.pop();
      if (elem2 > elem1)  // El mayor de ambos queda en elem1
	      elem1 = elem2;
    } else
      salir = true;
    pila_menor.push(elem1);
  }
  pila_menor.write();
  
  return 0;
}
