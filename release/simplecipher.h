/*
SIMPLE MULTI-CIPHER CIPHER DECODER
simplecipher.h

A header file that provides functions to encode/decode ciphers. 

Included functions:
(Function - Description)
atbash(string input)                        - Atbash cipher encoder/decoder. Returns a string.
caesar(string input, int shift)             - Caesar cipher encoder/decoder. Returns a string.
vigenereEncode(string input, string key)    - Optimized vigenere cipher encoder. Returns a string.
vigenereDecode(string input, string key)    - Optimized vigenere cipher decoder. Returns a string.
generateSquare()                            - Initialized the vigenere square. Required to be called first before utilizing vigenere encode/decode operations.
printSquare()                               - Output the vigenere square stored in memory.

Usage instructions:
The use of this header file requires #include<simplecipher.h>
BEFORE USING VIGENERE FUNCTIONS, initialize the square first by calling: generateSquare()


*/
#ifndef SIMPLECIPHER_H
#define SIMPLECIPHER_H

#include <string>

using namespace std;

string caesar(string userInput, int userShift);
string atbash(string userInput);

class simplecipher
{
public:
	simplecipher();
	~simplecipher();
};

namespace vigenere
{
	string encode(string userInput, string rawUserKey);
	string decode(string userInput, string rawUserKey);
	void generateSquare();
};


#endif