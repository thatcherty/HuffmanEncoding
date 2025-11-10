#pragma once
#include "TreeNode.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class HuffmanTree
{
public:
	HuffmanTree(string s);
	void compress(string s);
	string decode();
	void printMapping();
private:
	void frequencies(string s);
	void getMapping();
	template <typename cmp>
	void buildTree(priority_queue<TreeNode*, vector<TreeNode*>, cmp>& nodes);
	TreeNode* root;
	unordered_map<char, string> mapping;
	string encoded;
};

