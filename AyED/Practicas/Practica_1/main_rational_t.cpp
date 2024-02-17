// AUTOR: Joan Carlos García Méndez
// FECHA: 13/02/2024
// EMAIL: alu0101656571@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t

// pauta de estilo [92]: comentarios multilínea usando solo "//."

#include <iostream>
#include <cmath>

// pauta de estilo [41]: ficheros de cabecera agrupados y separados.
#include "rational_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3), c; // Declaración de 3 racionales,

  cout << "a.value()= " << a.value() << endl; // Escribe el valor de a.
  cout << "b.value()= " << b.value() << endl; // Escribe el valor de b.
  cout << "c.value()= " << c.value() << endl; // Escribe el valor de c.
  // Escribe los racionales en pantalla.
  cout << "a: ";
  a.write(); // Escribe el racional a.
  cout << "b: ";
  b.write(); // Escribe el racional b.

  c.read(); // Lee el racional c desde el teclado.
  cout << "c: "; 
  c.write(); // Escribe el racional c.

  // FASE II
  rational_t x(1, 3), y(2, 3);
  x.write(); // Escribe el racional x.
  y.write(); // Escribe el racional y.
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl; // Compara si x es igual que y, escribe el resultado.
  cout << "x < y? " << (x.is_greater(y) ? "true" : "false") << endl; // Compara si x es menor que y, escribe el resultado.
  cout << "x > y? " << (x.is_less(y) ? "true" : "false") << endl; // Compara si x es mayor que y, escribe el resultado.
  cout << "x == 0?" << (x.is_zero() ? "true" : "false") << endl; // Compara si x es igual a 0.
  cout << "y == 0?" << (y.is_zero() ? "true" : "false") << endl; // Compara si y es igual a 0.

  // FASE III
  cout << "a + b: ";
  a.add(b).write(); // Suma los racionaes a y b, escribe el resultado.
  
  cout << "b - a: ";
  b.substract(a).write(); // Resta los raciones a y b, escribe el resultado.

  cout << "a * b: ";
  a.multiply(b).write(); // Multiplica los racionales a y b, escribe el resultado.
  
  cout << "a / b: ";
  a.divide(b).write(); // Divide los racionales a y b, escribe el resutado.

 cout << "num / √den: ";
 a.root().write_root();

  return 0;
}