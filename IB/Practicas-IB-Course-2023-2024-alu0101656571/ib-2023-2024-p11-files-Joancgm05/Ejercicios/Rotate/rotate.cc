/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date
 * @brief
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>
#include <fstream>
#include <string>

char rotar_vocal(char c) {
  switch (c) {
    case 'a': return 'e';
    case 'e': return 'i';
    case 'i': return 'o';
    case 'o': return 'u';
    case 'u': return 'a';
    case 'A': return 'E';
    case 'E': return 'I';
    case 'I': return 'O';
    case 'O': return 'U';
    case 'U': return 'A';
    default: return c;
  }
}

void rotar_vocales(std::string& palabra) {
  for (char& c : palabra) {
    c = rotar_vocal(c);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Uso: " << argv[0] << " rotate_file" << std::endl;
    return 1;
  }

  std::ifstream archivo_entrada(argv[1]);
  if (!archivo_entrada.is_open()) {
    std::cerr << "No se pudo abrir el archivo de entrada: " << argv[1] << std::endl;
    return 1;
  }

  std::string linea;
  while (std::getline(archivo_entrada, linea)) {
    rotar_vocales(linea);
    std::cout << linea << std::endl;
  }

  archivo_entrada.close();

  return 0;
}
 
