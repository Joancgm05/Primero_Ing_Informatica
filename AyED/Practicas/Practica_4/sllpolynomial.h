// AUTOR: Joan Carlos Garcia Méndez 
// FECHA: 01/04/2024
// EMAIL: alu0101656571@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6
                
typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  // constructores
  SllPolynomial(void) : sll_t() {}; // constructor por defecto
  SllPolynomial(const vector_t<double>&, const double = EPS); // constructor de copia

  // destructor
  ~SllPolynomial() {}; // destructor de la clase

  // E/S
  void Write(std::ostream& = std::cout) const; // escribe el polinomio
  
  // operaciones
  double Eval(const double) const; // evalúa el polinomio en x
  bool IsEqual(const SllPolynomial&, const double = EPS) const; // comparación del polinomio con tolerancia EPS
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS); //suma de polinomios con  tolerancia EPS
};


bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II
// constructor
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  for (int i{v.get_size() - 1}; i >= 0; --i) { // Recorremos el vector desde el final
    if (IsNotZero(v.at(i), eps)) { // comprobamos si el valor es distinto de 0
      pair_double_t p(v.at(i), i); // Creamos un pair_double_t con el valor y el indice
      SllPolyNode* aux = new SllPolyNode(p); // Creamos un nodo con el pair
      push_front(aux); // Insertamos el nodo en la lista
    }
  } 
}


// E/S
void SllPolynomial::Write(std::ostream& os) const { // escribe el polinomio
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}


// Operaciones con polinomios

// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  SllPolyNode* aux(get_head()); // Creamos un auxiliar para recorrer la lista

  while (aux != NULL) { // Mientras no lleguemos al final de la lista
    int index(aux->get_data().get_inx()); // Obtenemos el indice
    double val(aux->get_data().get_val()); // Obtenemos el valor
    result = result + val * pow(x, index); // Calculamos el resultado
    aux = aux->get_next(); // Avanzamos al siguiente nodo
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol, const double eps) const {
  bool differents = false;
  SllPolyNode* aux(get_head()); // Creamos un auxiliar para recorrer la lista, del primer polinomio
  SllPolyNode* second_aux(sllpol.get_head()); // Creamos un auxiliar para recorrer la lista del segundo polinomio

  while (aux != NULL && second_aux != NULL) { // Mientras no lleguemos al final de la lista
    int index(aux->get_data().get_inx()); // Obtenemos el indice del primer polinomio
    double val(aux->get_data().get_val()); // Obtenemos el valor del primer polinomio
    int segundo_inx(second_aux->get_data().get_inx()); // Obtenemos el indice del segundo polinomio
    double segundo_val(second_aux->get_data().get_val()); // Obtenemos el valor del segundo polinomio

    if (index != segundo_inx && val != segundo_val) { // Si los indices o los valores son distintos
      return differents; 
    }
    aux = aux->get_next(); // Avanzamos al siguiente nodo del primer polinomio
    second_aux = second_aux->get_next(); // Avanzamos al siguiente nodo del segundo polinomio
  }
  if (aux != NULL || second_aux != NULL) { // Si alguno de los dos polinomios tiene mas elementos devuelvo false
    return differents;
  }
  return !differents;
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial& sllpol, SllPolynomial& sllpolsum, const double eps) {
  SllPolynomial auxSllPolSum; // Creamos un polinomio auxiliar
  SllPolyNode* aux = get_head(); // Creamos un auxiliar para recorrer la lista, del primer polinomio
  SllPolyNode* aux2 = sllpol.get_head(); // Creamos un auxiliar para recorrer la lista del segundo polinomio
  pair_double_t pair; // Creamos un pair_double_t para guardar el valor e indice
  double sum = 0.0;

  // si tienen los mismos exponentes se suman
  while (aux != NULL || aux2 != NULL) { // Mientras no lleguemos al final de la lista
    if (aux != NULL && aux2 != NULL) { // Si los dos polinomios igual tamaño
      if (aux->get_data().get_inx() == aux2->get_data().get_inx()) { // Si los indices son iguales
        sum = aux->get_data().get_val() + aux2->get_data().get_val(); // Sumamos los valores
        if (IsNotZero(sum, eps)) { // Si la suma no es 0
          pair.set(sum, aux->get_data().get_inx()); // Guardamos la suma e indice en el pair
          auxSllPolSum.push_front(new SllPolyNode(pair)); // Guardamos el pair en el polinomio auxiliar
        }
        if (aux != NULL) aux = aux->get_next(); // Avanzamos al siguiente nodo del primer polinomio
        if (aux2 != NULL) aux2 = aux2->get_next(); // Avanzamos al siguiente nodo del segundo polinomio
      } else if (aux->get_data().get_inx() > aux2->get_data().get_inx()) { // Si el indice del primer polinomio es mayor
        sum = aux2->get_data().get_val(); // Guardamos la suma del segundo polinomio
        if (IsNotZero(sum, eps)) { // Si la suma no es 0  
          pair.set(sum, aux2->get_data().get_inx()); // Guardamos la suma e indice en el pair
          auxSllPolSum.push_front(new SllPolyNode(pair));// Guardamos el pair en el polinomio auxiliar
        }
        if (aux2 != NULL) aux2 = aux2->get_next(); // Avanzamos al siguiente nodo del segundo polinomio
      } else {
        sum = aux->get_data().get_val(); // Guardamos la suma del primer polinomio
        if (IsNotZero(sum, eps)) { // Si la suma no es 0
          pair.set(sum, aux->get_data().get_inx()); // Guardamos la suma e indice en el pair
          auxSllPolSum.push_front(new SllPolyNode(pair));// Guardamos el pair en el polinomio auxiliar
        }

        if (aux != NULL) aux = aux->get_next(); // Avanzamos al siguiente nodo del primer polinomio
      }
                                                         // Si alguno de los dos polinomios esta vacio
    } else if (aux == NULL) {                            // Si el primer polinomio esta vacio
      sum = aux2->get_data().get_val(); // Guardamos la suma del segundo polinomio
      if (IsNotZero(sum, eps)) { // Si la suma no es 0
        pair.set(sum, aux2->get_data().get_inx()); // Guardamos la suma e indice en el pair
        auxSllPolSum.push_front(new SllPolyNode(pair)); // Guardamos el pair en el polinomio auxiliar
      }
      if (aux2 != NULL) aux2 = aux2->get_next(); // Avanzamos al siguiente nodo del segundo polinomio

    } else if (aux2 == NULL) { // Si el segundo polinomio esta vacio
      sum = aux->get_data().get_val(); // Guardamos la suma del primer polinomio
      if (IsNotZero(sum, eps)) { // Si la suma no es 0
        pair.set(sum, aux2->get_data().get_inx()); // Guardamos la suma e indice en el pair
        auxSllPolSum.push_front(new SllPolyNode(pair)); // Guardamos el pair en el polinomio auxiliar
      }

      if (aux != NULL) aux = aux->get_next(); // Avanzamos al siguiente nodo del primer polinomio
    }
  }

  while (!auxSllPolSum.empty()) { // Mientras el polinomio auxiliar no este vacio
    sllpolsum.push_front(auxSllPolSum.pop_front()); // Guardamos el polinomio auxiliar en el polinomio suma
  }

}


#endif  // SLLPOLYNOMIAL_H_
