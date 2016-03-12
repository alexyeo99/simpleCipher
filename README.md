# simpleCipher
A C++ library that provides functions for encoding and decoding Atbash, Caesar and Vigenere Ciphers.
# Usage
The only required files are simplecipher.h and simplecipher.cpp. The rest like demo.cpp are for convenience.
1. Copy simplecipher.cpp and simplecipher.h into your project directory.
2. To be able to use the code on your own project, add #include "simplecipher.h"
  * When accessing vigenere cipher encode/decode functions, use vigenere.encode() and vigenere.decode()

>Function usage:
  1. atbash(string ciphertext);
  2. caesar(string ciphertext,int shift);
  3. vigenere.encode(string ciphertext,string key);
  4. vigenere.decode(string ciphertext,string key);

*string ciphertext refers to either encoded or decoded text to be processed by the function.

# Sample program

#include <iostream>
#include "simplecipher.h"

using namespace std;

int main(){
  //atbash encode/decode
  cout << atbash("Put encoded/decoded text here.") << endl;
  
  //caesar encode/decode
  cout << caesar("Put the to-be encoded or decodex text here",-4) << endl; //the second argument specifies the shift. A shift of negative 4 means 4 letter backward.
  
  //vigenere encode
  cout << vigenere.encode("Put to-be encoded stuff here","KEY") << endl;
  
  //vigenere decode
  cout << vigenere.decode("Put to-be decoded stuff here","KEY")<< endl;
  
  return 0;
}
