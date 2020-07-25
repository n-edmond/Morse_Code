#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include<string>

using namespace std;
/***********************************************************************************************************

CREATE NODES FOR BINARY TREE. USING INSTEAD OF BUNCH OF GETTERS
SETTERS LIKE LAST PROGRAM

************************************************************************************************************/

struct BTNode 
{
	string data;
	BTNode* left_n;
	BTNode* right_n;

	BTNode(string t_val = "", BTNode* t_left = NULL, BTNode* t_right = NULL)
	{//paramerterized constructor for default
		data = t_val;
		left_n = t_left;
		right_n = t_right;
	}

	~BTNode() {};//destructor.
};

class Binary_Tree
{
public:
//CONSTRUCTORS
	Binary_Tree();//default constructor
	Binary_Tree(BTNode* newroot);//paramerterized

//GETTERS
	BTNode* get_Root();
	Binary_Tree get_Left_Subtree();
	Binary_Tree get_Right_Subtree();

//SETTER
	void set_root(BTNode* data);
	Binary_Tree(const string& str, const Binary_Tree& left = Binary_Tree(), const Binary_Tree& right = Binary_Tree()) 
	{
		root = new BTNode(str, left.root, right.root);
	}//sets the BTNode values

private:
	BTNode* root;
};
#endif