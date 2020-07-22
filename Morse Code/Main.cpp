#include <iostream>
#include <vector>
#include "BST.h"

using namespace std;

/*************************************************************************************************************************************************

This program will encode a given string to morse code. Case does not matter here.
This program will decode a given string of morse code with space as delimiter. Space is important here. Must be entered "._ ."
The program will give an error message and end if an unrecognized character is detected. Please ensure that you have entered your string correctly

*************************************************************************************************************************************************/

void encoder(string str);//encodes a given string
void decoder(string str);//decodes a given string

int main()
{
	string userString = "AbCdefghijklmNopqrsTuvwxyZ"; //change string here. test value
	string userStringMorse = "_. ._";//change morse code string here. test value
    BST Tree;

    cout << "Binary Search Tree\n-----------------\n";
    Tree.display_Binary_Tree();
    cout << endl << endl;

    cout << "Morse Code Chart:\n-----------------\n";
    Tree.display();
    cout << endl << endl;


	//encode here
    encoder(userString);

	//decode here
    //decoder(userStringMorse);

	return 0;
}
void encoder(string str)
{//encodes a given string by removing any spaces and adding char to vector OR STRING NOT SURE WHICH I WANT TO DO YET
	BST Tree;
    vector<char> temp_char_holder;
    for (int i = 0; i < str.length(); ++i)
    {
        if (isspace(str[i]))
        {
            //cout << " " << endl;
            continue;
        }
        if (!isalpha(str[i]))
        {
            cout << "Unrecognized character encountered. Only eneter letters from English alphabet. Please try again. Ending program." << endl;
            return;
        }
        else
        {
            str[i] = tolower(str[i]);
            temp_char_holder.push_back(str[i]);
        }

    }
    cout << "Encoding the following string: " << str << endl;
    for (int i = 0; i < temp_char_holder.size(); ++i)
    {
        
        cout << Tree.find(temp_char_holder.at(i));
    }
    cout << endl;

}


void decoder(string str)
{//decodes a given string by removing any spaces and converting to char SAME AS ABOVE MIGHT NEED TO CREATE A FUNCTION WITHIN THE CLASS? NOT SURE
	
    cout << "Decoding the given morse code: " << str << endl;
    return;
}