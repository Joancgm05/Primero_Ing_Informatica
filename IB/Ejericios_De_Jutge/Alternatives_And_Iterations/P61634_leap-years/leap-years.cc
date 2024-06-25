#include <iostream>

bool IsLeapYear(const int year) {
  if((year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)){               
    std::cout << "YES" << '\n';
    return 1;
  }
  else{
    std::cout << "NO" << '\n';
  }
  return 0; 
}

int main() {
  int year;
  std::cin >> year;
  IsLeapYear(year);
  return 0;
}
