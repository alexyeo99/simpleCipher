# Simple Cipher Library
A C++ library that provides functions for encoding and decoding Atbash, Caesar and Vigenere Ciphers. These are primitive ciphers that can be done on paper.
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

## Future development ideas
1. Create unit tests