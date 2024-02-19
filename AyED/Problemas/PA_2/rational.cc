#include <iostream>
#include <cassert>

class rational_t {
public:
  rational_t(const int = 0, const int  = 1);
  ~rational_t();

  int get_num() const { return num; }
  int get_den() const { return  den; }

  rational_t add(const rational_t& r);
  void write(std::ostream& = std::cout) const;
private:
  int num, den;
};

rational_t::rational_t(const int n, const int d) {
  //std::assert(d != 0);
}