#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

  
 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      //poner código
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      // poner código
      operate_(c);
    }
  }
  // poner código
  int resultado = stack_.top();
  stack_.pop();
  return (resultado);
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c');

  
  int resultado;
  //aridad 1
  if (c == 'r' || c == 'l' || c == 'c') {
    int num = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila un operando: " << num << std::endl;
    switch(c) {
      case 'r':
        resultado = sqrt(num);
        break;
      
      case 'l':
        resultado = log2(num);
        break;
      
      case 'c':
        resultado = num * num;
        break;
    }
  } else {
    // poner código
    int num2 = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila un operando: " << num2 << std::endl;
    // poner código
    int num1 = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila otro operando: " << num1 << std::endl;
    
    switch (c) {
    case '+':
      resultado = num1 + num2;
      // poner código
      break;
    case '-':
      resultado = num1 - num2;
      break;
    // poner código resto de operadores
    case '/':
      resultado = num1 / num2;
      break;
    
    case '*':
      resultado = num1 * num2;
      break;
    
    case '^':
      resultado = pow(num1, num2);
      break;
    }

  }
  // poner código
  stack_.push(resultado);
  std::cout << "   Metemos en la pila el resultado: " << resultado << std::endl;
}

 
#endif  // RPNT_H_
