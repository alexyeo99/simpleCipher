/*
SIMPLE CIPHER DECODER
simplecipher.cpp

Refer to the first block comment at simplecipher.h for more details.

*/


//Includes go here
#include <string>
#include "simplecipher.h"
//#include "stdafx.h" //FOR VS

//using namespace std;

//Universal variable declarations start here
char vigSquare[26][26]; //the main vigenere square
bool squareInit = false;
//Universal variable declarations stop here

//Declare the functions to be used.
/* string vigenereDecode(string userInput,string userKey);
string vigenereEncode(string userInput, string userKey);
string caesar(string userInput, int userShift);
string atbash(string userInput);
void generateSquare(); */
//commented. lets see if its required.

/*
VIGENERE CIPHER DECODER FUNCTION
*/
string vigenere::decode(string userInput, string rawUserKey) {
	//see if square was not initialized. this will not work if it isn't.
	if(squareInit == false){
		generateSquare();
	}
	string output = "";
	//Now, process the key to filter invalid stuff.
	string userKey = "";
	for (int i = 0; i < rawUserKey.length(); i++)
	{
		char tempChar = tolower(rawUserKey[i]);
		if (tempChar >= 97 && tempChar <= 122)
		{
			userKey = userKey + tempChar;
		}
	}
	//get charcount of key and input
	int userInputCnt = userInput.length();
	int userKeyCnt = userKey.length();
	int keyCounter = 0;
	
	for (int i = 0; i < userInputCnt; i++)
	{
		char outputChar = 'a';
		char currChar = userInput[i]; // this is so manupulations can be done.
										// Ex: for uppercase / lowercase conversions.
		//add support for upper charachters
		bool makeUpper = false;
		if (userInput[i] >= 65 && userInput[i] <= 90)
		{
			makeUpper = true;
			//convert to lowercase for compatibility
			currChar = tolower(currChar);
		}

		//make sure only valid chars from user input are processed
		if ((userInput[i] >= 97 && userInput[i] <= 122) || makeUpper)
		{
			//get letter distance from a on key
			int charDist = userKey[keyCounter] - 97;
			int tempCode = currChar - 97 - charDist;
			//handle tempcode underflow
			if (tempCode < 0)
			{
				int compensate = 0 - tempCode;
				tempCode = 26 - compensate;
			}
			outputChar = vigSquare[0][tempCode];//utilize ony 1 line.
			if (makeUpper)
			{
				outputChar = toupper(outputChar);
			}
			output = output + outputChar; 
			//increment char used on key

			if (keyCounter + 1 >= userKeyCnt)
			{
				keyCounter = 0;
			}
			else {
				keyCounter++;
			}
		}
		else
		{
			output = output + (char)userInput[i];
		}
		
	}
	return output;
}


/*
VIGENERE SQUARE GENERATOR FUNCTION
A function to generate the vigenere square that the program utilizes. Automatically executes when a vigenere decoder object is created.
*/
void vigenere::generateSquare() {
	int w = 0;
	while (w < 26)
	{
		int x = 0;
		while (x < 26)
		{
			int tempchar = 97 + x + w;
			//handle overflows
			if (tempchar > 122)
			{
				int x = tempchar - 122;
				tempchar = x + 96;
			}
			vigSquare[w][x] = (char)tempchar;
			x++;
		}
		w++;
	}
	squareInit = true;
}



/*
VIGENERE CIPHER ENCODER FUNCTION
*/
string vigenere::encode(string userInput, string rawUserKey){
	string output = "";
	//see if square was not initialized. this will not work if it isn't.
	if(squareInit == false){
		generateSquare();
	}
	//Now, process the key to filter invalid stuff.
	string userKey = "";
	for (int i = 0; i < rawUserKey.length(); i++)
	{
		char tempChar = tolower(rawUserKey[i]);
		if (tempChar >= 97 && tempChar <= 122)
		{
			userKey = userKey + tempChar;
		}
	}
	//get charcount of key and input
	int userInputCnt = userInput.length();
	int userKeyCnt = userKey.length();
	int keyCounter = 0;

	for (int i = 0; i < userInputCnt; i++)
	{
		char outputChar = 'a';
		char currChar = userInput[i]; // this is so manupulations can be done.
									  // Ex: for uppercase / lowercase conversions.
									  //adds support for upper charachters
		bool makeUpper = false; //deermines if the char is uppercase.
		if (userInput[i] >= 65 && userInput[i] <= 90)
		{
			makeUpper = true;
			//convert to lowercase for compatibility
			currChar = tolower(currChar);
		}

		//make sure only valid chars from user input are processed
		if ((userInput[i] >= 97 && userInput[i] <= 122) || makeUpper)
		{
			//get letter distance from a on key
			int charDist = userKey[keyCounter] - 97;
			outputChar = vigSquare[userKey[keyCounter]-97][currChar-97];//utilize ony 1 line.
			if (makeUpper)
			{
				outputChar = toupper(outputChar);
			}
			output = output + outputChar;
			//increment char used on key

			if (keyCounter + 1 >= userKeyCnt)
			{
				keyCounter = 0;
			}
			else {
				keyCounter++;
			}
		}
		else
		{
			output = output + (char)userInput[i];
		}

	}
	return output;
}




/*
CAESAR CIPHER ENCODER/DECODER FUNCTION
Comments:
>A positive shift indicates shifting letters forward.
>A negative shift means x letters backward.
*/
string caesar(string userInput, int userShift) {
	string output = "";
	for (int i = 0; i < userInput.length(); i++)
	{
		char temp = 'a';
		temp = userInput[i];
		bool makeUpper = false;
		if (isupper(temp))
		{
			makeUpper = true;
		}
		
		//take out case sensitivity
		temp = tolower(temp);

		//do the shift if it is a letter
		if (temp >=96 && temp <=122)
		{
			temp = temp + userShift;
			//do corrections
			//TODO: Make this into a while
			while (temp < 96 || temp > 122)
			{
				if (temp < 96) //handle undeflows
				{
					//get the difference
					int diff = 97 - temp;
					temp = 123 - diff;
				}
				//handle overflows
				if (temp > 122)
				{
					int diff = temp - 122;
					temp = 96 + diff;
				}
				
			}
		}
	
		//commit change
		//handle uppercase
		if (makeUpper)
		{
			temp = toupper(temp);
		}
		output = output + temp;
	}
	return output;
}



/*
ATBASH CIPHER ENCODER/DECODER FUNCTION
*/
string atbash(string userInput) {
	string output = "";
	for (int i = 0; i < userInput.length(); i++)
	{
		char temp = userInput[i];
		bool makeUpper = false;
		if (isupper(temp))
		{
			makeUpper = true;
		}
		//take out case snsitivity
		temp = tolower(temp);
		if (temp >=96 || temp <=122) //process supported chars only
		{
			int k = 122 - temp;
			k = 97 + k;
			
			temp = k;
		}
		//process uppercase
		if (makeUpper)
		{
			temp = toupper(temp);
		}
		output = output + temp;
	}
	return output;
}

simplecipher::simplecipher()
{
}


simplecipher::~simplecipher()
{
}
