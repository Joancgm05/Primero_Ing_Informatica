/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *  
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date Mes Día Año
 * @brief this program declare and initialize variables of arithmetic 
 *        types and print on the screen the result of operating those
 *        variables with all the operators that you can use with them.
 * @bug 0 bugs
 */

#include <iostream>

int main() {
  int numero_uno, numero_dos;
  std::cin >> numero_uno >> numero_dos;
  std::cout << numero_uno << " + " << numero_dos << " = " 
            << numero_uno + numero_dos << '\n';
  std::cout << numero_uno << " - " << numero_dos << " = "
            << numero_uno - numero_dos << '\n';
  std::cout << numero_uno << " * " << numero_dos << " = "
            << numero_uno * numero_dos << '\n';
  std::cout << numero_uno << " / " << numero_dos << " = "
            << numero_uno / numero_dos << '\n';
  std::cout << numero_uno << " % " << numero_dos << " = "
            << numero_uno % numero_dos << '\n';

bool menor, mayor, menor_igual, mayor_igual, igual;
menor = numero_uno < numero_dos;
mayor = numero_uno > numero_dos;
menor_igual = numero_uno <= numero_dos;
mayor_igual = numero_uno >= numero_dos;
igual = numero_uno == numero_dos;

  std::cout << numero_uno << " < " << numero_dos << " = "
            << menor << '\n';
  std::cout << numero_uno << " > " << numero_dos << " = "
            << mayor << '\n';
  std::cout << numero_uno << " <= " << numero_dos << " = "
            << menor_igual << '\n';
  std::cout << numero_uno << " >= " << numero_dos << " = "
            << mayor_igual << '\n';
  std::cout << numero_uno << " == " << numero_dos << " = "
            << igual << '\n';

return 0;
}
