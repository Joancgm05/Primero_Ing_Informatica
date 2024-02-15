// AUTOR: Joan Carlos García Méndez
// FECHA: 13/02/2024
// EMAIL: alu0101656571@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

//Según la guía de estilo de google para comentar secciones enteras hay que utilizar "/* */" en lugar de "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public:
  rational_t(const int = 0, const int = 1); // Constructor, parametrizado
  ~rational_t() {} // Destructor
  
  // pauta de estilo [71]: indentación a 2 espacios
  // getters
  int get_num() const; // Método para obtener el numerador 
  int get_den() const; // Método para obtener el denominador 
  
  // setters
  void set_num(const int); // Método para modificar el numerador 
  void set_den(const int); // Método para modificar el denominador 

  // value
  double value(void) const;

  // FASE II
  // bool is_equal(const rational_t&, const double precision = EPSILON) const;
  // bool is_greater(const rational_t&, const double precision = EPSILON) const;
  // bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  // rational_t add(const rational_t&);
  // rational_t substract(const rational_t&);
  // rational_t multiply(const rational_t&);
  // rational_t divide(const rational_t&);
  
  void write(ostream& = cout) const; // Método para escribir un racional mediante teclado
  void read(istream& = cin); // Método para leer un racional 
  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_; // Atributos privados de la clase rational_t
};
