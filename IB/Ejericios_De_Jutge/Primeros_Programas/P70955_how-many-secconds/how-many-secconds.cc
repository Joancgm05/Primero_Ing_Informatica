/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date Oct 28th 2023
 * @brief this program converts to seconds a given amount of 
          anios << days << hours << minutes and seconds.
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */
 
#include <iostream>

int main() {
  int anios, dias, horas, minutos, segundos;
  std::cin >> anios >> dias >> horas >> minutos >> segundos;
  anios = anios * 31536000;
  dias = dias * 86400;
  horas = horas * 3600;
  minutos = minutos * 60;
  segundos = segundos;
  std::cout << anios + dias + horas + minutos + segundos << '\n';
  return 0;
}
