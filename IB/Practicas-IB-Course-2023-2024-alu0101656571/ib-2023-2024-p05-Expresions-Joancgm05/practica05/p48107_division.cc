/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 * @file 
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date oct 15th 2023
 * @brief this program prints in the terminal de result of the
 *        operation of two integrers numbers 
 * @bug Nº de bugs
 * @see https:g/jutge.org/problems/
 */

#include<iostream>

int main() {
  int numero_uno, numero_dos;
  std::cin >> numero_uno >> numero_dos;
 
  if (numero_dos > 0) {
    std::cout << numero_uno / numero_dos << std::endl;
    std::cout << numero_uno % numero_dos << std::endl;
} 
 else {
    if (numero_dos < 0) {
    std::cout << "Error: b < 0" << std::endl;
    }
}
return 0;
}
