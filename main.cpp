#include <iostream>
#include "poly.h"


using namespace std;

void dispMenu();

int main(){
  Poly A;
  Poly B;

  int input=0;

  while( input != 5 ){
    dispMenu();
    while( (!cin >> input) ){
      cin.clear();
      cout << "Please Enter an integer" << endl;
    }

    switch( input ){
    case 1:
      cin >> A;
      break;
    case 2:
      cin >> B;
      break;
    case 3:
      cout << A + B << endl;
      break;
    case 4:
      cout << A - B << endl;
      break;
    case 5:
      break;
    default:
      cout << "Whooops, not a valid choice." << endl;
    }

  }
  return 0;
}


void dispMenu(){
  cout << "1: Enter Polynomial A\n2: Enter Polynomial B\n3: Add Polynomials( A + B )\n4: Subtract Polynomials( A - B )\n5: Quit" << endl;

}
