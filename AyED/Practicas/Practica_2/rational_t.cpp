// AUTOR: Joan Carlos García Méndez 
// FECHA: 
// EMAIL: alu0101656571@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0); // Comprueba que el denominador no sea 0
  num_ = n, den_ = d; // Asigna el numerador y el denominador
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
inline
int
rational_t::get_num() const // Obtiene el numerador
{
  return num_;
}



inline
int
rational_t::get_den() const // Obtiene el denominador
{
  return den_;
}


  
void
rational_t::set_num(const int n) // Asigna el numerador
{
  num_ = n; // Asigna el numerador 
}


  
void
rational_t::set_den(const int d) // Asigna el denominador
{
  assert(d != 0); // Comprueba que el denominador no sea 0
  den_ = d; // Asigna el denominador
}



inline
double
rational_t::value() const // Devuelve el valor del racional
{ 
  return double(get_num()) / get_den();
}



rational_t 
rational_t::opposite() const // Devuelve el racional opuesto
{ 
  return rational_t((-1)*get_num(), get_den());
}



rational_t
rational_t::reciprocal() const // Devuelve el racional reciproco
{ 
  return rational_t(get_den(), get_num());
}



// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const // Compara si dos números racionales son iguales
{ 
  return fabs(value() - r.value()) < precision;
}



bool
rational_t::is_greater(const rational_t& r, const double precision) const // Compara si el número racional es mayor que otro
{
  return (value() - r.value()) > precision;
}



bool
rational_t::is_less(const rational_t& r, const double precision) const // Compara si el número racional es menor que otro
{
  return r.is_greater(*this, precision);
}


// operaciones
rational_t
rational_t::add(const rational_t& r) const // Se suman dos racionales y se devuelve el resultado.
{
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), 
                    get_den() * r.get_den());
}



rational_t
rational_t::substract(const rational_t& r) const // Se restan dos racionales y se devuelve el resultado.
{
  return add(r.opposite());
}



rational_t
rational_t::multiply(const rational_t& r) const // Se multiplican dos racionales y se devuelve el resultado.
{
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}



rational_t
rational_t::divide(const rational_t& r) const // Se dividen dos racionales y se devuelve el resultado.
{
  return multiply(r.reciprocal());
}


// FASE I: operadores
// Sobrecarga del operador de suma
rational_t
operator+(const rational_t& a, const rational_t& b) 
{
  return a.add(b);
}


// Sobrecarga del operador de resta
rational_t
operator-(const rational_t& a, const rational_t& b)
{
  return a + b.opposite();
}


// Sobrecarga del operador de multiplicación
rational_t
operator*(const rational_t& a, const rational_t& b)
{
  return a.multiply(b);
}


// Sobrecarga del operador de división
rational_t
operator/(const rational_t& a, const rational_t& b)
{
  return a.divide(b);
}



// E/S
// Escribir el número racional y su valor
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl; 
}


// Lee un racional desde el flujo de salida.
void
rational_t::read(istream& is)
{
  is >> num_ >> den_;
  assert(den_ != 0);
}


// Sobrecarga del operador de salida
ostream&
operator<<(ostream& os, const rational_t& r)
{
  r.write(os);
  return os;
}

// Sobrecarga del operador de entrada 
istream&
operator>>(istream& is, rational_t& r)
{
  r.read(is);
  return is;
}