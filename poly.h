#ifndef POLY
#define POLY

#include <iostream>

using namespace std;

class Poly
{
 public: 
  /**
   *Friend Overload for cin >> operator
   *WARNING: Will interupt and ask for new input if not valid
   *Accepts input of form (n is int) [-]nx^2[+,-]nx[+,-]n
   **/
  friend istream& operator>> (istream&, Poly&);
  
  /**
   *Friend Overload output operator see >> doc for form, no newline or flush
   **/
  friend ostream& operator<< (ostream&, const Poly&);
  
  /**
   *Overloads +/- operator, follows standard math behavior for polynomials 
   **/
  friend Poly operator+(const Poly&, const Poly&);
 
  friend Poly operator-(const Poly&, const Poly&);

  
 private:
  //what you think they are
  int x2;
  int x;
  int ones;

};

#endif
