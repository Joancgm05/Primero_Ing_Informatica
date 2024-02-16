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
// Google style: Para comentar secciones enteras hay que utilizar "/* */" en lugar de "//".

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d) // Constructor, parametrizado
{
  assert(d != 0); // Si el denominador es igual a 0, se aborta el programa 
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos
// Google style: 1 línea de separación entre métodos.

// pauta de estilo [83]: tipo retornado en línea anterior al método
// Google style: tipo de retorno antes del método

int
rational_t::get_num() const // Obtiene el numerador 
{
  return num_; // Delvuelve el valor del denominador 
}



int
rational_t::get_den() const // Obtiene el denominador 
{
  return den_; // Devuelve el valor del denominador 
}


  
void
rational_t::set_num(const int n) // Define el numerador 
{
  num_ = n; // No debuelve nada 
}


  
void
rational_t::set_den(const int d) // Define el denominador
{
  assert(d != 0); // Si el denominador el 0, aborta el programa 
  den_ = d; // No devuelve nada 
}


// Devuelve el valor del racional como un double 
double
rational_t::value() const 
{ 
  return double(get_num()) / get_den();
}


// comparaciones
// Compara si dos racionales son iguales 
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{
  return fabs(value() - r.value()) < precision;
}


// Compara si un racional es mayor que otro
bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
  return r.value() - value() > precision;
}



bool
rational_t::is_less(const rational_t& r, const double precision) const
{
  return value() - r.value() > precision;
}



bool
rational_t::is_zero(const double precision) const
{
  return fabs(value()) < precision;
}



// operaciones
// Se suman dos racionales y se devuelve el resultado 
rational_t
rational_t::add(const rational_t& r)
{
  double num = (get_num() * r.get_den()) + (get_den() * r.get_num());
  double den = get_den() * r.get_den();
  return rational_t(num, den);
}



// Se restan dos racionales y se devuelve el resultado 
rational_t
rational_t::substract(const rational_t& r)
{
  double num = (get_num() * r.get_den()) - (get_den() * r.get_num());
  double den = get_den() * r.get_den();
  return rational_t(num, den);
}



// Se multiplican dos racionales y se devuelve el resultado
rational_t
rational_t::multiply(const rational_t& r)
{
  double num = get_num() * r.get_num();
  double den = get_den() * r.get_den();
  return rational_t(num, den);
}



// Se dividen dos racionales y se devuelve el resultadog
rational_t
rational_t::divide(const rational_t& r) 
{
  double num = get_num() * r.get_den();
  double den = get_den() * r.get_num();
  return rational_t(num, den);
}



// E/S
// Escribe un racional en el flujo de salida 
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}


// Lee un racional desde el flujo de salida 
void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
