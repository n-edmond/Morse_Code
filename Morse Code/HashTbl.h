#pragma once
#include <string>
#include <unordered_map>//to allow insertion of letters in any order.

using namespace std;

/***********************************************************************************************************

Creates a hash table. Map is unordered as order does not matter and is used for encoding

************************************************************************************************************/

class HashTbl
{//USED TO LINK THE CHARACTER TO THEIR MORSE TRANSLATION

public:
//FUNCTION
	void add_To_Hash(string alph, string morse);

//GETTER
	string get_Morse_Characters(string alph);

private:
	unordered_map<string, string> dictionary;
};


