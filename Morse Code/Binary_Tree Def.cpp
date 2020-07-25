#include<iostream>
#include<string>
#include "Binary_Tree.h"
#include <fstream>

using namespace std;

//CONSTRUCTORS
Binary_Tree::Binary_Tree()
{//default constructor.
	root = new BTNode();
}

Binary_Tree::Binary_Tree(BTNode* newroot)
{//paramerterized constructor
	root = newroot;
}

//GETTERS
BTNode* Binary_Tree::get_Root()
{//gets the root of tree
	return root;
}

Binary_Tree Binary_Tree::get_Left_Subtree()
{//gets the left portion of tree
	return Binary_Tree(root->left_n);
}

Binary_Tree Binary_Tree::get_Right_Subtree()
{//gets the right branch of tree
	return Binary_Tree(root->right_n);
}

//SETTERS
void Binary_Tree::set_root(BTNode* t_root)
{//saves the value of the root
	root = t_root;
}