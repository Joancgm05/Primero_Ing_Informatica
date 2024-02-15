/*#include <format>
#include <iostream>
#include <limits>
#include <cstdint>

int main() {
  double max_d {std::numeric_limits<double>::max()};
  double lowest_d {std::numeric_limits<double>::lowest()};
  double min_d {std::numeric_limits<double>::min()};
  double denorm_d {std::numeric_limits<double>::denorm_min()};
  
  double d {0.0d};

  max_d - 1.0d;

  std::cout << std::format{"Max double {}", max_d} << '\n';
  std::cout << std::format{"Lowest double {}", lowest_d} << '\n';
  std::cout << std::format{"Min double {}", min_d} << '\n';
  std::cout << std::format{"Denorm min double {:.10}", denorm_d} << '\n';
  std::cout << std::format{"d {}", min_d} << '\n';
  std::cout << std::format{"Max (bits) {:#x}", reinterpret_cast} << '\n';
  std::cout << std::format{"Max pert {}", } << '\n';
  return 0;
}
*/