#ifndef BST_H
#define BST_H

#include<string>
#include "BST_Node.h"
#include <fstream>

using namespace std;
/************************************************************************************************************************************************

This class acts pretty similarly to your Binary_Search_Tree.h. I felt that only a few of the functions listed were necesssary so I only used
a few ideas. 

************************************************************************************************************************************************/

class BST
{
public:
	BST();//default constructor
	~BST();//destructor

//FUNCTIONS
	void display_Binary_Tree();//will display the binary search tree of the morse code
	void display();//to display the tree and possible letters. not sure yet. may call on display_Binary_tree_function? will be using inorder traversal of tree
	void insert(const char new_character, char* const new_string);//adds item to bst
	string find(char c);//finds occurence of given character
	//void erase();wrapper function she used is a bit confusing. not entirely needed if i do it all in one

//GETTER
	BST_Node* get_Root()const;

//SETTER
	void set_Root(BST_Node* const new_root);

private:
//OVERLOADED FUNCTIONS. decided to make private since there isnt much of a need to mess with these. Might change later?
	void display(BST_Node* Tree);
	void insert(BST_Node*& new_node, const char chr, char *const str);
	void erase(BST_Node *main_root);
	BST_Node* new_Node(const char new_character, char* new_string);
	string find(BST_Node* Tree, char chr);

	//VARIABLES
	BST_Node *nodeParent;
	


};
#endif