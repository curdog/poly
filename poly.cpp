#include <iostream>
#include <string>
#include <ctype.h>
#include "poly.h"

using namespace std;

istream& operator>>(istream& inp, Poly& p1){
   string temp;
   bool valid = false;
   while( !valid ){
     getline(inp,temp);
     //check for x^2, x
     //store positions for them so we can calculate where the 
     //number substring partitions are,
     int x2l = temp.find("x^2");
     int xl = temp.find("x");
     //the last one will be after a plus or minus sign after x
     //we can just compute it
     
     if(  xl == string::npos || x2l == string::npos ){
       valid = false;
       cout << "error in expression, re-enter" << endl;
       continue;
     }
     
     string numTemp; 
     // x2 and x as constants for the varibles, intruducting c as the ones constant
     int x2, x, c;
     //adjust the substrings to not include the leading x
     x2 = atoi( temp.substr( 0, x2l - 1 ).c_str() );
     //add the length of x^2, don't want the 2 being counted as well
     x = atoi( temp.substr( x2l + 3, xl - 1  ).c_str() );
     //same deal as x2, though keep the sign
     c = atoi( temp.substr(xl+1, temp.length() ).c_str() );
      
   }
   
   
 }
ostream& operator<<(ostream& outp, const Poly& pol){
   //negatives will count as the sign, watch for + though, will not output a sign
   outp << pol.x2 << "x^2"<< ((pol.x >=0)?"+":"") << pol.x 
	<< ((pol.ones >= 0)?"+":"") << pol.ones;
   return outp;
  
 }
 Poly::Poly operator+(const Poly& left, const Poly& right){
   Poly temp;
   temp.x2 = left.x2 + right.x2;
   temp.x = left.x + right.x;
   temp.ones = left.ones + right.ones;
   return temp;
   
 }
 Poly::Poly operator-(const Poly& left, const Poly& right){
   Poly temp;
   temp.x2 = left.x2 - right.x2;
   temp.x = left.x - right.x;
   temp.ones = left.ones - right.ones;
   return temp;
 }



