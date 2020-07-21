#ifndef BST_NODE_H
#define BST_NODE_H

#include<string>
#include <vector>

using namespace std;

/************************************************************************************************************************************************

This class acts pretty similarly to your class with the structs in it. I did not want to copy your code since I was a bit confused on what some of the
functions were supposed to be doing and I wasn't sure how to use it to translate it the way I was aiming for 

************************************************************************************************************************************************/


//MIGHT CHANGE THIS PART INTO A STRUCT? NOT SURE YET, WILL KEEP THIS WHILE I CREATE THE PROGRAM
class BST_Node
{
public:
	BST_Node();//default constructor
	BST_Node(char character, char *string);//parameterized constructor
	~BST_Node();//destructor

//GETTERS
	char get_Character() const;
	string getString() const;
	BST_Node*& get_Left_Node();
	BST_Node*& get_Right_Node();

//SETTERS
	void set_Character(const char chr);
	void set_String(char* const str);
	void set_Left(BST_Node* const nodeLeft);
	void set_Right(BST_Node* const nodeRight);

private:
	//VARIABLES
	char character;
	char given_string[100];//since string is array of characters, opting to use an array for simplicity
	BST_Node* nodeLeft;
	BST_Node* nodeRight;

};
#endif