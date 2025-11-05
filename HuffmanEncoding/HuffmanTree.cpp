#include "HuffmanTree.h"

string HuffmanTree::compress(string s)
{

    frequencies(s);

    //buildTree(frequencies(s));

    return "This is a test";

}

string HuffmanTree::decode()
{
    return string();
}

void HuffmanTree::printFreq()
{

}

vector<TreeNode*> HuffmanTree::frequencies(string s)
{
    unordered_map<char, int> freq{};
    vector<TreeNode*> nodes{};

    // O(s.length())
    for (int i = 0; i < s.length(); i++)
    {
        ++freq[s[i]];
    }

    // O(n = unique val in s)
    for (auto p : freq)
    {
        nodes.push_back(new TreeNode(p.second, p.first));
    }

    // O(nlogn) avg
    sort(nodes.begin(), nodes.end(), [](TreeNode*& n1, TreeNode*& n2)
        {
            return n1->getVal() < n2->getVal();
        });

    return nodes;
}

void HuffmanTree::buildTree(vector<TreeNode*> nodes)
{
    
}
