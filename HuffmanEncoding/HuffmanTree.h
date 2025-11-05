#pragma once
#include "TreeNode.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class HuffmanTree
{
public:
	static string compress(string s);
	static string decode();
	void printFreq();
private:
	static vector<TreeNode*> frequencies(string s);
	static void buildTree(vector<TreeNode*> nodes);
	TreeNode* root;
	string encoded;
};

