#include <iostream>
#include <cstring>
#include <cassert>


int main() {
  std::uint64_t uvar1 {0x8000000000000000}; // Este número es negativo sin signo
  std::uint64_t uvar2 {0x7fffffffffffffff};
  std::uint64_t var1 {};
  std::uint64_t var2 {};
  std::memcpy(&var1,&uvar1,8);
  std::memcpy(&var2,&uvar2,8);


  var2 = var2 + 1; 
 
  // OVERFLOW! ME quedo fuera, Se sale del rango y se produce un overflow dandome el numero negativo por tanto la igualadad es factible    
  assert(var1 == var2);
  std::cout << "Ok!" << '\n';

  return 0;
}
