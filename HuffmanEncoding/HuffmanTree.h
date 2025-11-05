#pragma once
#include "TreeNode.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class HuffmanTree
{
public:
	HuffmanTree(string s);
	void compress(string s);
	string decode();
	void printFreq();
private:
	vector<TreeNode*> frequencies(string s);
	void buildTree(vector<TreeNode*> nodes);
	TreeNode* root;
	string encoded;
};

