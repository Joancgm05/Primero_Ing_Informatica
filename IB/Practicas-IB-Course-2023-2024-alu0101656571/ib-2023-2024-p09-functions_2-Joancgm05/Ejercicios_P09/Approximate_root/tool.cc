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
#include <vector>
#include "tool.h"

double approximateRoot(double number) {
  double root = 1.0;
  double delta = 1.0;
  const double EPSILON = 1e-4;
    
  while (std::fabs(root * root - number) > EPSILON) {
    if (delta > 0) {
      while (root * root < number) {
        root += delta;
      }   
    } else {
        while (root * root > number) {
          root += delta;
        }
      }   

        delta *= -0.5;
    }   

    return root;
}
 
