#include <string>
#include "BST.h"

using namespace std;

BST::BST()
{//uses values of Binary Tree as the default
	Binary_Tree();
}

void BST::insert(BTNode*& node, string morse, string alph)
{//inserts the given character to a new node if specific conditions are met
	if (node == NULL)
	{//checks condition of node
		node = new BTNode();
	}
	if (morse.size() == 0)
	{//checks size of the morse code array
		node->data = alph;
	}
	else if (morse[0] == '.')
	{//inserts the node to the left if '.' is encountered/ creating tree
		insert(node->left_n, morse.substr(1), alph);//copies morse string starting at element 1
	}
	else if (morse[0] == '_')
	{//inserts the node to the right if '_' is encounterd. creating tree
		insert(node->right_n, morse.substr(1), alph);
	}
}