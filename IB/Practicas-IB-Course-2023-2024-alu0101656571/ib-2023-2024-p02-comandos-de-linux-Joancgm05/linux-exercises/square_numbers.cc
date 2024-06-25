/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 20 Jul 2020
 * @brief  Computes the Sum of Square of first n Natural numbers. 
 * @version 21.09.2023
 *
 */

#include<iostream>

int main() {
  int number;
  std::cout << "Enter any number: ";
  std::cin >> number;

  int square;
  int sum = 0; 
  for(int i = 1; i <= number; ++i) {
    square = i * i;
    sum += square;
  }

  std::cout<<"\nSum of square of [ "<< number <<" ] Numbers = " << sum << "\n";
  return 0;
}
