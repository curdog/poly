#ifndef POLY
#define POLY

#include <iostream>

using namespace std;

class Poly
{
 public: 
  friend istream& operator>> (istream&, Poly&);
  friend ostream& operator<< (ostream&, const Poly&);
  friend Poly operator+(const Poly&, const Poly&);
  friend Poly operator-(const Poly&, const Poly&);

  
 private:
  int x2;
  int x;
  int ones;

};

#endif
