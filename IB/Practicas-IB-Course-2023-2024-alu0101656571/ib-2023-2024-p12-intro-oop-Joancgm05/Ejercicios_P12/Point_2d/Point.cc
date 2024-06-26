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

class Point2D {
 private:
  double x;
  double y;

public:
  // Constructor
  Point2D(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

  // Método para mostrar las coordenadas del punto
  void Show() const {
    std::cout << x << ", " << y << '\n';
  }

  // Método para cambiar las coordenadas del punto
  void Move(double deltaX, double deltaY) {
    x += deltaX;
    y += deltaY;
  }

  // Método para calcular la distancia entre dos puntos
  double Distance(const Point2D& otherPoint) const {
    double deltaX = x - otherPoint.x;
    double deltaY = y - otherPoint.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
  }

  // Método para calcular el punto medio entre dos puntos
  Point2D Middle(const Point2D& otherPoint) const {
    double midX = (x + otherPoint.x) / 2.0;
    double midY = (y + otherPoint.y) / 2.0;
    return Point2D(midX, midY);
  }
};

int main() {
  // Ejemplo de uso de la clase Point2D
  Point2D point1(1.0, 2.0);
  Point2D point2(4.0, 6.0);

  std::cout << "Coordenadas del punto 1: ";
  point1.Show();

  std::cout << "Coordenadas del punto 2: ";
  point2.Show();

  // Movemos el punto 1
  point1.Move(2.0, -1.0);
  std::cout << "Después de mover el punto 1: ";
  point1.Show();

  // Calculamos la distancia entre los dos puntos
  double distance = point1.Distance(point2);
  std::cout << "Distancia entre los dos puntos: " << distance << std::endl;

  // Calculamos el punto medio entre los dos puntos
  Point2D midPoint = point1.Middle(point2);
  std::cout << "Punto medio entre los dos puntos: ";
  midPoint.Show();

  return 0;
}
