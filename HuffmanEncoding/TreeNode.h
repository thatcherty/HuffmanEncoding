#pragma once
#include <iostream>

using namespace std;

class TreeNode
{
public:
	TreeNode(int val = 0, char c = '\0', TreeNode* left = nullptr, TreeNode* right = nullptr);
	void setNext(TreeNode* next, bool left);
	TreeNode* getNext(bool left);
	int getVal();
	void setVal(int val);
	void printNode();

private:
	int val;
	char c;
	TreeNode* left;
	TreeNode* right;
};

