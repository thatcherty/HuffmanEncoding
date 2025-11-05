#include "TreeNode.h"

TreeNode::TreeNode(int val, char c, TreeNode* left, TreeNode* right)
{
	this->val = val;
	this->c = c;
	this->left = left;
	this->right = right;
}

void TreeNode::setNext(TreeNode* next,  bool left)
{
	if (left)
	{
		this->left = next;
	}
	else
	{
		this->right = next;
	}
}

TreeNode* TreeNode::getNext(bool left)
{
	return left ? this->left : this->right;
}

int TreeNode::getVal()
{
	return this->val;
}

void TreeNode::setVal(int val)
{
	this->val = val;
}

void TreeNode::printNode()
{
	cout << this->c << ": " << this->val << endl;
}
