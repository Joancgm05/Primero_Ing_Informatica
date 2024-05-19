#include <iostream>

using namespace std;

int main() {
  short a = 5;
  float b = 12.6;
  short *a_ptr = &a; 
  float *b_ptr = &b;
  cout << "a=" << a << '\t';
  cout << "a_ptr=" << a_ptr;
  cout << "\t*a_ptr=";
  cout << *a_ptr << endl; 
  cout << "b=" << b << '\t';
  cout << "b_ptr=" <<  b_ptr;
  cout << "\t*b_ptr=";
  cout << *b_ptr << endl; 
}