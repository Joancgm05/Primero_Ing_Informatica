/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date oct 22th 2023
 * @brief this program reads two numbers a and b, and prints 
          all numbers between a and b
 * @bug 0 bugs
 * @see https://jutge.org/problems/P97156_en
 */

#include <iostream>

int main() {
  int number_one, number_two;
  std:: cin >> number_one >> number_two;

  for (int lowest_number = number_one; lowest_number <= number_two; lowest_number++) {
    if (lowest_number > number_one) {
    std::cout << ",";
    }
    std::cout << lowest_number;
  }
  std::cout << '\n';
   
  return 0;
}
