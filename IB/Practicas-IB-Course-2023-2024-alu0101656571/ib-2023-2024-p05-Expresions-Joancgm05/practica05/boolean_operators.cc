/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *  
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date oct 15th 2023
 * @brief This program prints in the screen de table of the thruth
 *        that gives the result of operate tow variables with all
 *        its possible values with each of its logical operators
 * @bug 0 bugs
 */

#include <iostream>

int main() {
  bool variable1, variable2;  

  std::cout << " La tabla de verdad es: " << '\n';
  std::cout << " p " << " q " << " p && q " << " p || q " << " !p " << " !q " << '\n';
  std::cout << " 1 " << " 1 " << "   1    " << "   1    " << "  0  " << " 0  " << '\n';
  std::cout << " 1 " << " 0 " << "   0    " << "   1    " << "  0  " << " 1  " << '\n';
  std::cout << " 0 " << " 1 " << "   0    " << "   1    " << "  1  " << " 0  " << '\n';
  std::cout << " 0 " << " 0 " << "   0    " << "   0    " << "  1  " << " 1  " << '\n';

return 0;
}
