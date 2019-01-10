#include <iostream>
#include "simplecipher.h"

using namespace std;

int main(){
  //Khoor wkhuh. wklv lv d whvw phvvdjh
  //shift: 3
  //decode the message
  cout << caesar("Khoor wkhuh. wklv lv d whvw phvvdjh",-3) << endl;
	
  //zexaz xzedt. elas uh uykt edxi kayewi leji.
  //KEY:Sample
  //decode the message
  cout << vigenere::decode("Zexaz xzedt. Elas uh uykt edxi kayewi leji.","Sample") << endl;
  return 0;
}
