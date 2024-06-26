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
#include <cmath>

// Enumeración para representar colores del círculo
enum Color {
  ROJO,
  VERDE,
  AZUL
};

class Circulo {
 private:
  double centroX;
  double centroY;
  double radio;
  Color color;

 public:
  // Constructor
  Circulo(double x, double y, double r, Color c) : centroX(x), centroY(y), radio(r), color(c) {}

  // Método para calcular el área del círculo
  double Area() const {
    return 3.14159 * radio * radio;
  }

  // Método para calcular el perímetro del círculo
  double Perimetro() const {
    return 2 * 3.14159 * radio;
  }

  // Método para imprimir la información del círculo en pantalla
  void Print() const {
    std::cout << "Centro: (" << centroX << ", " << centroY << ")" << std::endl;
    std::cout << "Radio: " << radio << std::endl;
    std::cout << "Color: ";
    switch (color) {
      case ROJO:
        std::cout << "Rojo";
        break;
      case VERDE:
        std::cout << "Verde";
        break;
      case AZUL:
        std::cout << "Azul";
        break;
      default:
        std::cout << "Desconocido";
    }
    std::cout << std::endl;
  }

  // Método para determinar si un punto (x, y) está dentro del círculo
  bool EsInterior(double x, double y) const {
    double distanciaAlCentro = std::sqrt(std::pow(x - centroX, 2) + std::pow(y - centroY, 2));
    return distanciaAlCentro <= radio;
  }
};

int main() {
  // Ejemplo de uso de la clase Circulo
  Circulo circulo1(0.0, 0.0, 5.0, AZUL);

  // Imprimir información del círculo
  std::cout << "Información del círculo:" << std::endl;
  circulo1.Print();

  // Calcular y mostrar área y perímetro
  std::cout << "Área del círculo: " << circulo1.Area() << std::endl;
  std::cout << "Perímetro del círculo: " << circulo1.Perimetro() << std::endl;

  // Verificar si un punto está dentro del círculo
  double xPunto = 2.0;
  double yPunto = 3.0;
  if (circulo1.EsInterior(xPunto, yPunto)) {
    std::cout << "(" << xPunto << ", " << yPunto << ") está dentro del círculo." << std::endl;
  } else {
    std::cout << "(" << xPunto << ", " << yPunto << ") está fuera del círculo." << std::endl;
  }

  return 0;
}
