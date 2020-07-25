#include <iostream>
#include "Conversions.h"
#include "Binary_Tree.h"

using namespace std;

/*************************************************************************************************************************************************

This program will encode a given string to morse code. Case does not matter here.
This program will decode a given string of morse code with space as delimiter. Space is important here. Must be entered "._ ."
The program will give an error message and end if an unrecognized character is detected. Please ensure that you have entered your string correctly

*************************************************************************************************************************************************/


int main()
{
	string userString = "Te St"; //change string here. test value
	string userStringMorse = "_ . ... _";//change morse code string here. test value
    Convert morse_converter;
	morse_converter.retrieve_File_Info();
	string encoded_val = morse_converter.encoder(userString);
	string decoded_val = morse_converter.decoder(userStringMorse);

	cout << "\n\n                  Binary Search Tree\n ----------------------------------------------------\n";
	morse_converter.print_BST();

	

	//cout << encoded_val;
	cout << "\n\n\n           Encoding the given string: " << userString << " \n ----------------------------------------------------\n" << encoded_val << endl << endl;
	//cout << "\n\n\n           Decoding the given morse code: " << userStringMorse << " \n ----------------------------------------------------\n" << decoded_val << endl << endl;
	cout << "Please uncomment the desired function to check encoder/decoder" << endl;
	


	return 0;
}



