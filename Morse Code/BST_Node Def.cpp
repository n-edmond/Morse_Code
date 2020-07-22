#include "Bst_Node.h"
#include <iostream>
#include <cctype>

using namespace std;

/*****************************************************************************************************************************
DONE FOR NOW MAY NEED TO COME BACK TO EDIT. 
*****************************************************************************************************************************/

BST_Node::BST_Node() 
{//default constructor. Dont intend to use
	char given_string[100];
	character = ' ';
	nodeLeft = nullptr;
	nodeRight = nullptr;
}

BST_Node::BST_Node(char chr, char* string)
{//parameterized constructor
	strcpy_s(given_string, string);//copies the string parameter into the given_string array.
	this->character = chr;
	this->nodeLeft = nullptr;
	this->nodeRight = nullptr;

}//parameterized constructor
BST_Node::~BST_Node()
{//destructor
	//cout << "DELETE ME. DESTRUCTOR FUNCT. TEST" << endl;
}

//GETTERS
char BST_Node::get_Character() const
{
	return character;
}
string BST_Node::getString() const
{
	return given_string;
}
BST_Node *&BST_Node::get_Left_Node()
{
	return nodeLeft;
}
BST_Node*& BST_Node::get_Right_Node()
{
	return nodeRight;
}

//SETTERS
void BST_Node::set_Character(const char chr) 
{
	this->character = chr;
}
void BST_Node::set_String(char* const str)
{
	strcpy_s(given_string, str);
}
void BST_Node::set_Left(BST_Node* const nLeft)
{
	this->nodeLeft = nLeft;
}
void BST_Node::set_Right(BST_Node* const nRight)
{
	this->nodeRight = nRight;
}