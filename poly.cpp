#include <iostream>
#include <string>
#include "poly.h"

 Poly::istream& operator>>(istream& inp, Poly& p1){
   string temp;
   bool valid = false;
   while( !valid ){
     getline(inp,temp);
     //check for x^2, x
     //store positions for them so we can calculate where the number substrings are
     int x2l = temp.find("x^2");
     int xl = temp.find("x");
     if(  x == string::npos || x2 == string::npos ){
       valid = false;
       continue;
     }
     // x2 and x as constants for the varibles, intruducting c as the ones constant
     int x2, x, c;
     x2 = atoi( temp.substr( 0, x2l - 1 ) );
     x = atoi( temp.substr( 
     
      

   }
   
   
 }
 Poly::ostream& operator<<(ostream& outp, const Poly& p1){
   
  
 }
 Poly::Poly operator+(const Poly& left, const Poly& right){
   
 }
 Poly::Poly operator-(const Poly& left, const Poly& right){
   
 }



