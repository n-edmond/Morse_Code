#pragma once
#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#include<string>
#include "BST.h"
#include "HashTbl.h"

using namespace std;

/***********************************************************************************************************

Converter. Encoder, Decoder, Print, Retrieve Files done here

************************************************************************************************************/

class Convert
{
public:
//CONSTRUCTORS
	Convert() {
		morseTree = BST();
	}
	//default constructor
	void retrieve_File_Info();
	void print_BST();
	string find(BTNode *&node, string input);
	string encoder(string input);
	string decoder(string input);

private:
	BST morseTree;
	HashTbl morseHash;
	int print_count = 10;
	void print_BST(BTNode* node, int space);
};
#endif