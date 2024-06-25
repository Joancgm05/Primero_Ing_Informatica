/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date 29 oct 2023
 * @brief this program reads a number and prints in the screen
          if that year is leap
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */
 
#include <iostream>

void LeapYear(int year) {
  if (year == 2000) {
  std::cout << "YES" << '\n';
  return;
  }
  int temp{year % 4};
  int temp_two{year % 100};
  if (temp == 0 && temp_two != 0) {
    std::cout << "YES" << '\n';
  }
    else {
      int temp_three{year / 100};
      int temp_four{temp_three % 4};
      if (temp_two == 0 && temp_three == 0) {
        std::cout << "YES" << '\n';
      }
      else {
        std::cout << "NO" << '\n';
      }
    }
}

int main() {
  int year; 
  std::cin >> year;
  LeapYear(year);
  return 0;
}
