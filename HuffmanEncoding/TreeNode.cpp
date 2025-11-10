#include "TreeNode.h"

TreeNode::TreeNode(int val, char c, TreeNode* left, TreeNode* right)
{
	this->val = val;
	this->c = c;
	this->left = left;
	this->right = right;
}

void TreeNode::setNext(TreeNode* next,  bool right)
{
	if (right)
	{
		this->right = next;
	}
	else
	{
		this->left = next;
	}
}

TreeNode* TreeNode::getNext(bool right)
{
	return right ? this->right : this->left;
}

int TreeNode::getVal()
{
	return this->val;
}

char TreeNode::getChar()
{
	return c;
}

void TreeNode::setVal(int val)
{
	this->val = val;
}

void TreeNode::printNode()
{
	cout << this->c << ": " << this->val << endl;
}
