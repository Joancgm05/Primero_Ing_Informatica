#include <iostream>
#include <vector>
#include <cassert>

typedef double (*function_ptr)(double); // Crea un alias para la función
typedef std::vector<double> points_container; // Crea un alias para un vector

class func_eval {
 public:
  func_eval(const double left, const double right, const double eps, const function_ptr function) {
    assert(right >= left +eps);
    fill_x(x_, left, right, eps);
  }
 private:
   points_container x_;
   points_container y_;
   void fill_x(points_container & x, const double left, const double right, const double eps) {
     double point (left);
     while (point <= right) {
       x.emplace_back(point);
       point += eps;
     }
   }
   void eval(const points_container & x , points_container & y, function_ptr function) {
     for (const double point : x) {
       y.emplace_back(function(point));
     }
   }
};