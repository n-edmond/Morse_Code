#include <string>
#include <unordered_map>//to allow insertion of letters in any order.
#include "HashTbl.h"

using namespace std;


void HashTbl::add_To_Hash(string alph, string morse_char)
{//sets the letter value as key, morse characters as the values. will be used for encoding/decoding
	dictionary[alph] = morse_char;
}

string HashTbl::get_Morse_Characters(string alph)
{//retrieves value of the given letter
	return dictionary[alph];
}