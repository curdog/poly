#include <iostream>
#include "poly.h"

 Poly::istream& operator>>(istream& inp, Poly& p1){
   int temp;
   getline(inp,temp);
   int find(string& str)
   
   
 }
 Poly::ostream& operator<<(ostream& outp, const Poly& p1){
   
  
 }
 Poly::Poly operator+(const Poly& left, const Poly& right){
   Poly temp;
   temp.x2 = left.x2 + right.x2;
   temp.x = left.x + right.x;
   temp.one = left.one + right.one;
   return temp;
   
 }
 Poly::Poly operator-(const Poly& left, const Poly& right){
   Poly temp;
   temp.x2 = left.x2 - right.x2;
   temp.x = left.x - right.x;
   temp.one = left.one - right.one;
   return temp;
 }



