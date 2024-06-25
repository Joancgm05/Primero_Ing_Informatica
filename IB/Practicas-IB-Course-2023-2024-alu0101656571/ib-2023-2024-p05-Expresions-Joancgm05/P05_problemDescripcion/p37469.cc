/* 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date oct 16th 2023
 * @brief 
 * @bug 0 bugs
 */

 #include <iostream>

int main() {
  int numero_segundos;
  std::cin >> numero_segundos;
  std::cout << numero_segundos / 3600 << " "; 
   
  std::cout << (numero_segundos % 3600) / 60 << " ";
  std::cout << numero_segundos % 60 << " " << '\n';

return 0;
}
