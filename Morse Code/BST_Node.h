#include<string>

struct Node
{
	char info;
	Node* left;
	Node* right;
};


class BST_Node
{
	BST_Node(char data, Node* left, Node* right);//constructor
	virtual ~BST_Node();//destructor

};