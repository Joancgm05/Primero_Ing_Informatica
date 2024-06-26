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
#include <sstream>
#include <vector>

bool es_vocal(char c) {
  c = std::tolower(c);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int contar_vocales(const std::string& palabra) {
  int conteo = 0;
  for (char c : palabra) {
    if (es_vocal(c)) {
      conteo++;
    }
  }
  return conteo;
}

int contar_consonantes(const std::string& palabra) {
  int conteo = 0;
  for (char c : palabra) {
    if (std::isalpha(c) && !es_vocal(c)) {
      conteo++;
    }
  }
  return conteo;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Uso: " << argv[0] << " vowels_and_consonants_file" << std::endl;
    return 1;
  }

  std::ifstream archivo(argv[1]);
  if (!archivo.is_open()) {
    std::cerr << "No se pudo abrir el archivo: " << argv[1] << std::endl;
    return 1;
  }

  std::string palabra;
  std::string palabra_max_vocales, palabra_max_consonantes;
  int max_vocales = 0, max_consonantes = 0;

  while (archivo >> palabra) {
    int vocales = contar_vocales(palabra);
    int consonantes = contar_consonantes(palabra);

    if (vocales > max_vocales || (vocales == max_vocales && palabra < palabra_max_vocales)) {
      palabra_max_vocales = palabra;
      max_vocales = vocales;
    }

    if (consonantes > max_consonantes || (consonantes == max_consonantes && palabra < palabra_max_consonantes)) {
      palabra_max_consonantes = palabra;
      max_consonantes = consonantes;
    }
  }

  archivo.close();

  std::cout << "Palabra con más vocales: " << palabra_max_vocales << " (" << max_vocales << " vocales)" << std::endl;
  std::cout << "Palabra con más consonantes: " << palabra_max_consonantes << " (" << max_consonantes << " consonantes)" << std::endl;

  return 0;
}
 
