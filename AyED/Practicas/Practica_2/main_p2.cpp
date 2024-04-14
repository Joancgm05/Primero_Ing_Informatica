// AUTOR: Joan Carlos García Méndez 
// FECHA: 01/03/2024
// EMAIL: alu0101656571@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_p2.cpp -o main_p2

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include <iostream>
#include <cmath>

// pauta de estilo [41]: ficheros de cabecera agrupados y separados
#include "rational_t.hpp"

#include "vector_t.hpp"

#include "matrix_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3); // Se crea un racional con numerador 1 y denominador 2 y otro con numerador 3 y denominador 1

  // FASE I
  cout << "a + b: "; // Se muestra por pantalla la suma de los racionales
  (a + b).write();

  cout << "b - a: "; // Se muestra por pantalla la resta de los racionales
  (b - a).write();

  cout << "a * b: "; // Se muestra por pantalla el producto de los racionales
  (a * b).write();
  
  cout << "a / b: "; // Se muestra por pantalla la división de los racionales 
  (a / b).write();
  
  cout << endl;
  
  // FASE II
  vector_t<double> v, w; // Se crean dos vectores de tipo double
  v.read(), v.write(); // Se leen y muestran por pantalla los vectores
  w.read(), w.write(); // Se leen y muestran por pantalla los vectores
  
  cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << endl << endl; // Se muestra por pantalla el producto escalar de los vectores
  
  vector_t<rational_t> x, y; // Se crean dos vectores de tipo rational_t
  x.read(), x.write();
  y.read(), y.write();
  
  cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << endl << endl; // Se muestra por pantalla el producto escalar de los vectores

  vector_t<double> z;
  z.read(), z.write();

  cout << "El vector circular de vector_t<rational>: " << circular_vect(z) << endl << endl;
  
  // FASE III
  matrix_t<double> A, B, C; // Se crean matrices de tipo double
  A.read(), A.write(); // Se leen y muestran por pantalla las matrices
  B.read(), B.write(); // Se leen y muestran por pantalla las matrices
  
  C.multiply(A, B); // Se multiplican las matrices A y B, se almacena en C
  cout << "Multiplicación de matrices A y B: " << endl; // Se muestra por pantalla la multiplicación de las matrices
  C.write();
  
  return 0;
}