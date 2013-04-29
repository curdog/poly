#include <iostream>
#include <string>
#include <cctype>
#include "poly.h"

//for viewing of string partitions
#define NDEBUG

using namespace std;

istream& operator>>(istream& inp, Poly& p1){
   string temp;
   bool valid = false;
   while( !valid ){
     inp.clear(); //kill everything before it
     inp.ignore( 2, '\n'); //works this way, kills newline from last, prevents spurious error in reading

     getline(inp,temp);
     //check for x^2, x
     //store positions for them so we can calculate where the 
     //number substring partitions are,
     int x2l = temp.find("x^2");
     int xl = temp.find("x", x2l+1);
     //the last one will be after a plus or minus sign after x
     //we can just compute it
     
     if(  xl == string::npos || x2l == string::npos ){
       valid = false;
       cout << "error in expression, re-enter" << endl;
       continue;
     }
     
     string numTemp; 
     // x2 and x as constants for the varibles, intruducting c as the ones constant
     //adjust the substrings to not include the leading x
     p1.x2 = atoi( temp.substr( 0, x2l ).c_str() );
     //add the length of x^2, don't want the 2 being counted as well
     p1.x = atoi( temp.substr( x2l + 3, xl  ).c_str() );
     //same deal as x2, though keep the sign
     p1.ones = atoi( temp.substr(xl+1, temp.length() ).c_str() );
#ifdef DEBUG
     cout << temp.substr( 0, x2l) << endl;
     cout << temp.substr( x2l+3, xl ) << endl;
     cout << temp.substr( xl+1, temp.length() ) << endl;
#endif
     //now to cheat so to speak, so there should be only:
     //3/4 punc ( -,^, +/-, +/- ) 2 chars (x's)
     int alphas = 0;
     int puncs = 0;
     for( int i = 0; i < temp.length(); i++ ){
       if( ispunct( temp.at( i ) ) ){ puncs++;}
	 
       if( isalpha( temp.at(i ) ) ){ alphas++;}

     }
     if( !( puncs == 3 || puncs == 4) || !(alphas == 2 ) ){
	 valid = false;
	 continue;
     }


     //this should be good now
     valid = true;
   }
   
   
 }
ostream& operator<<(ostream& outp, const Poly& pol){
   //negatives will count as the sign, watch for + though, will not output a sign
  outp << pol.x2 << "x^2"<< ((pol.x >=0)?"+":"") << pol.x << "x" 
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



