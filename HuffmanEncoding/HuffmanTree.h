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
	string decode();
	void printMapping();
	void printEncoded();
private:
	void compress(string s);
	void frequencies(string s);
	void getMapping();
	void encode(string s);
	void buildTree();

	TreeNode* root;
	unordered_map<char, string> mapping;
	unordered_map<char, int> freq;
	string encoded;
};

