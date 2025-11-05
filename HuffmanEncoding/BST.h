#pragma once
#include "TreeNode.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class BST
{
public:
	BST(TreeNode* head = nullptr);
	void add(int num);
	void remove(int num);
	string search(int num);
	void in_order(TreeNode* root);
	TreeNode* top();
private:
	TreeNode* head;
};

