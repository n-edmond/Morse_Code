#include<iostream>
#include<string>
#include "BST.h"
#include <fstream>

using namespace std;

BST::BST()
{//default constructor. file is opened and iterated thorugh here. 
	char c = ' ';//may use /0 to represent null
	char s[100] = " ";//some arbitrary amount for array 
	nodeParent = nullptr;
	fstream MorseTxt;
	
	MorseTxt.open("morse");
	if (MorseTxt.fail()) {
		cout << "Could not open file." << endl;
	}

	while (!MorseTxt.eof())
	{
		MorseTxt >> c;
		MorseTxt.getline(s, 100);
		insert(c, s);
	}

	MorseTxt.close();
}
BST::~BST()
{
	erase(nodeParent);
}//destructor

//FUNCTIONS
void BST::display_Binary_Tree()
{//will display the binary search tree of the morse code in tree form
	cout << "FIX ME" << endl;
}

void BST::display()
{//to display the tree and possible letters. not sure yet. may call on display_Binary_tree_function?
	display(nodeParent);
}

void BST::display(BST_Node* Tree)
{//NOT SURE IF I WANT THIS? KEEP IDEA JUST IN CASE
	cout << "FIX ME" << endl;
	if (Tree != nullptr)
	{
		display(Tree->get_Left_Node());
		cout << Tree->get_Character() << " " << Tree->getString() << endl;
		display(Tree->get_Right_Node());
	}
}

void BST::insert(const char new_character, char* const new_string)
{//adds item to bst
	insert(nodeParent, new_character, new_string);
}

void BST::insert(BST_Node*& new_node, const char chr, char *const str)
{//overloaded insertion feature
	if (new_node == nullptr)
	{
		BST_Node* temp = new BST_Node(chr, str);
		new_node = temp;
	}
	else
	{
		if (chr < new_node->get_Character())
		{
			insert(new_node->get_Left_Node(), chr, str);
		}
		else if (chr > new_node->get_Character())
		{
			insert(new_node->get_Right_Node(), chr, str);
		}
	}
}

string BST::find(char c)
{
	return find(nodeParent, c);

}

string BST::find(BST_Node* Tree, char chr)
{
	string S;
	if (Tree != nullptr)
	{
		find(Tree->get_Left_Node(), chr);
		find(Tree->get_Right_Node(), chr);
		if (Tree->get_Character() == chr)
		{
			cout << "TEST    " << Tree->getString() << endl;
			S = Tree->getString();
		}
	}
	return S;//might skip the variable step still laying down ideas before debugging
}

void BST::erase(BST_Node* main_root)
{
	if (main_root != nullptr)
	{
		erase(main_root->get_Left_Node());
		erase(main_root->get_Right_Node());
		cout << "TEST     ERASE FUNC  " << main_root->get_Character() << endl;
		delete(main_root);
	}
}

BST_Node* BST::new_Node(const char new_character, char* new_string)
{ 
	BST_Node* node = new BST_Node(new_character, new_string);
	return node;
}

//GETTERS
BST_Node* BST::get_Root()const
{//returns root
	return nodeParent;
}

//SETTERS
void BST::set_Root(BST_Node* const new_root)
{//sets the root
	this->nodeParent = new_root;
}