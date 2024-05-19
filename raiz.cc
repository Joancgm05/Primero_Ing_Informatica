#include <cmath>
#include <iostream>


// Implementa la función raiz que calcula la raíz cuadrada de un número
double raiz(const double x, double eps = 1e-6) { // x es el radicando y eps es la precisión
 double r = 0; // r es la raíz
 for (double v = 1; abs(r * r - x) > eps && abs(v) > eps; r += v) // Mientras la diferencia entre el cuadrado de la raíz y el radicando sea mayor que la precisión y la diferencia entre v y la precisión sea mayor que la precisión
   if (((r * r > x) and (v > 0)) || ((r * r < x) and (v < 0))) // Si el cuadrado de la raíz es mayor que el radicando y v es positivo o si el cuadrado de la raíz es menor que el radicando y v es negativo
     v *= -.5;
 return r;
}

int main() {
  int radicando{0};
  std::cin >> radicando;

  std::cout << raiz(radicando) << std::endl;

  return 0;
}