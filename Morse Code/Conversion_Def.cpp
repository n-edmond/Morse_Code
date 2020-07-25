#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include "Conversions.h"

using namespace std;

//Convert::Convert() {};

void Convert::retrieve_File_Info()
{
	ifstream morseTable;
	morseTable.open("morse.txt");
	string t_str = "";
	if (morseTable.fail()) {
		cout << "Could not open file." << endl;
		return;
	}

	while (morseTable.good())
	{//iterates thorugh file. saves to bst and dictionary for encoding/decoding

		morseTable >> t_str;
		string alph = t_str.substr(0, 1);//retrives the first character (ends at element 1)
		string morse = t_str.substr(1);//retrieves the morse code (starts at 1)
		BTNode* m_r = morseTree.get_Root();//retrieves root
		morseTree.insert(m_r, morse, alph);//adds to binary tree
		morseHash.add_To_Hash(alph, morse);//adds to dictionary

	}

	morseTable.close();
}

void Convert::print_BST(BTNode* node, int space) 
{//DISPLAYS THE BINARY TREE TO THE SCREEN. DISPLAYED SIDEWAYS.
	if (node == NULL)
		return;

	space += print_count;

	print_BST(node->right_n, space);

	cout << endl;
	for (int i = print_count; i < space; ++i)
		cout << ' ';

	cout << node->data << endl;

	print_BST(node->left_n, space);
}

void Convert::print_BST() 
{//PRINT WRAPPER FUNCTION
	print_BST(morseTree.get_Root(), 0);
}

string Convert::find(BTNode*& node, string input)
{//searches for position in binary tree of character
	//cout << node->data << endl;
	if ((node->data != "") && (input.size() == 0))
	{
		//cout << "RETURN DATA" << endl;
		return node->data;
	}
	else if (input.at(0) == '.')
	{//searches left side for character
		//cout << "IS PERIOD GOING LEFT" << endl;
		return find(node->left_n, input.substr(1));
	}
	else if (input.at(0) == '_')
	{//searches right side for character
		//cout << "IS UNDERSCORE GOING RIGHT" << endl;
		return find(node->right_n, input.substr(1));
	}
	else if (node == NULL)
	{
		//cout << "RETURN NOTHING" << endl;
		return "";
	}
	else
	{
		return "Invalid morse character found. Please check your file.\n";
	}
}

string Convert::encoder(string input)
{//endodes a english word to morse code. Will remove random spaces and character cases
	string result = "";
	string alph;
	input.erase(remove(input.begin(), input.end(), ' '));//removes all spaces from string

	for (int i = 0; i< input.length(); ++i)
	{
		if (!isalpha(input[i]))
		{//checks if it is a alpha. if not, ends program
			return"Unrecgonized character entered. Only eneter letters from English alphabet. Please try again. Ending program\n";
		}
		else
		{//changes string to all lower
			input[i] = tolower(input[i]);
		}
	}

	for (string::iterator iter = input.begin(); iter != input.end(); ++iter)
	{
		alph = *iter;
		result.append(morseHash.get_Morse_Characters(alph));
		result.append(" ");
	}

	return result;
}

string Convert::decoder(string input)
{//decodes morse code and returns the english word
	//char placeholder = ' ';
	string morse = "";
	BTNode* root = morseTree.get_Root();
	string result = "";

	for (unsigned long int i = 0; i < input.length(); ++i)
	{
		//placeholder = input[i];
		if (input.at(i) != ' ')
		{//if the character is not a blank, concatenate with morse
			morse += input.at(i);

			if (i == input.length() - 1)
			{//if at the end,iterate through morse tree to get root val
				result += find(root, morse);
			}
			if (input.at(i) != '.' && input.at(i) != '_')
			{//cout << "TAKE 2"
				return "Unrecognized character entered. Only uses . or _ for decoding. Ending program.\n";
			}
		}
		else if (input.at(i) == ' ')
		{//if the character is blank, concatenate the result with what you have found to get root val
			result += find(root, morse);
			morse = "";
		}
		else if (!isalpha(input.at(i)))
		{
			cout << "Test";
			return "";
		}

	}

	return result;
}