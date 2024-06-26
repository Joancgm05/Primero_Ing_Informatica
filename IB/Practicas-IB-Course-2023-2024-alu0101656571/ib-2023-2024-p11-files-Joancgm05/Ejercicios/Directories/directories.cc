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
#include <cctype>

void dividir_palabras(const std::string& texto, std::vector<std::vector<std::string>>& palabras_por_letra) {
  std::istringstream stream(texto);
  std::string palabra;

  while (stream >> palabra) {
    if (!palabra.empty()) {
      char primera_letra = std::toupper(palabra[0]);
      palabras_por_letra[primera_letra - 'A'].push_back(palabra);
    }
  }
}

void escribir_archivos(const std::vector<std::vector<std::string>>& palabras_por_letra) {
  for (char letra = 'A'; letra <= 'Z'; ++letra) {
    std::string nombre_archivo = std::string(1, letra) + ".txt";
    std::ofstream archivo(nombre_archivo);

    if (!archivo.is_open()) {
      std::cerr << "Error al abrir el archivo " << nombre_archivo << std::endl;
      continue;
    }

    for (const std::string& palabra : palabras_por_letra[letra - 'A']) {
      archivo << palabra << std::endl;
    }

    archivo.close();
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Uso: " << argv[0] << " directories_file" << std::endl;
    return 1;
  }

  std::ifstream archivo_entrada(argv[1]);
  if (!archivo_entrada.is_open()) {
    std::cerr << "No se pudo abrir el archivo de entrada: " << argv[1] << std::endl;
    return 1;
  }

  std::vector<std::vector<std::string>> palabras_por_letra(26); // 26 letras del alfabeto

  std::string linea;
  while (std::getline(archivo_entrada, linea)) {
    dividir_palabras(linea, palabras_por_letra);
  }

  archivo_entrada.close();

  escribir_archivos(palabras_por_letra);

  std::cout << "Archivos generados exitosamente." << std::endl;

  return 0;
}
 
