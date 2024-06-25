/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date Oct 28th 2023
 * @brief this program adds one second to a clock time, given 
          its hours, minutes and seconds.
 * @bug there are no bugs
 *
 * @see https://jutge.org/problems/P34279_en
 */
 
#include <iostream>

int main() {
  int horas, minutos, segundos;
  std::cin >> horas >> minutos >> segundos;
  segundos++;
  if (segundos == 60) {
  minutos++;
  segundos = segundos - 60; 
  }
  if (minutos == 60) {
  horas++;
  minutos = minutos - 60; 
  }
  if (horas >= 24) {
  horas = horas - 24;
  }
  if (horas < 10) {
  std::cout << "0";
  }
  std::cout << horas << ":";
  if (minutos < 10) {
  std::cout << "0";
  }
  std::cout << minutos << ":";
  if (segundos < 10) {
  std::cout << "0";
  }
  std::cout << segundos << '\n';
  return 0;
}
