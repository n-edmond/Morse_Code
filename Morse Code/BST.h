#ifndef BST_H
#define BST_H

#include<string>
#include <vector>
#include "Binary_Tree.h"

using namespace std;

/***********************************************************************************************************

Inserts nodes into binary Tree. Gets the info from BST's BTNode struct

************************************************************************************************************/

class BST :public Binary_Tree//needs Binary_Trees struct info
{
public:
	BST();//default constructor.
	void insert(BTNode*& node, string morse, string alph);
};
#endif