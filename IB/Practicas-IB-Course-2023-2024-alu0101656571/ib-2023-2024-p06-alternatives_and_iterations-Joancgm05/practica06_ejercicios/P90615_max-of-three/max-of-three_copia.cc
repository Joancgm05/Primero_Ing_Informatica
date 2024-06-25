/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 * 
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date oct 22th 2023
 * @brief this program reads three numbers and prints their maximum
 * @bug 0 bugs
 * @see https://jutge.org/problems/P90615_en
 */

#include<iostream>

int main() {  
  int number_one, number_two, number_three;
  std::cin >> number_one >> number_two >> number_three;
  int biggest_number {number_one};
  
  if (number_two > biggest_number) {
  biggest_number = number_two;
  }
    else {
      if (number_three > biggest_number) {
			biggest_number = number_three;
      }
    }
  std::cout << biggest_number << std::endl;

  return 0;
}
