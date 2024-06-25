/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date Oct 28th 2023
 * @brief this program given a number of seconds n, prints 
          the number of hours, minutes and seconds represented 
          by n
 * @bug there are no bugs
 *
 * @see https://jutge.org/problems/P37469_en
 */

#include <iostream>

int main() {
  int numero_segundos;
  std::cin >> numero_segundos;
  int horas, minutos, segundos;
  horas = numero_segundos / 3600;
  minutos = numero_segundos % 3600;
  segundos = minutos % 60;
  if (numero_segundos < 60) {
  minutos = 0;
  }
  if (minutos >= 60) {
  minutos = minutos / 60;
  }
  if (segundos >= 60) {
  segundos = segundos / 60;
  }
  std::cout << horas << " " << minutos << " " << segundos << '\n';
  return 0;
}
