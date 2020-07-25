#include <string>
#include <unordered_map>//to allow insertion of letters in any order.
#include "Create_Dictionary.h"

using namespace std;


void Create_Dictionary::add_To_Dict(string alph, string morse_char)
{//sets the letter value as key, morse characters as the values. will be used for encoding/decoding
	dictionary[alph] = morse_char;
}

string Create_Dictionary::get_Morse_Characters(string alph)
{//retrieves value of the given letter
	return dictionary[alph];
}