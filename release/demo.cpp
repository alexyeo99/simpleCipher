#include <iostream>
#include "simplecipher.h"

using namespace std;

int main(){
	//using this site: http://www.braingle.com/brainteasers/codes/caesar.php
	//Khoor wkhuh. wklv lv d whvw phvvdjh
	//decode the message
	cout << caesar("Khoor wkhuh. wklv lv d whvw phvvdjh",-3) << endl;
	
	//using this site:
	//zexaz xzedt. elas uh uykt edxi kayewi leji.
	//KEY:Sample
	//decode the message
	cout << vigenere::decode("Zexaz xzedt. Elas uh uykt edxi kayewi leji.","Sample") << endl;
	return 0;
}
