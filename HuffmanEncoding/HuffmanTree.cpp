#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(string s)
{
    compress(s);
}

void HuffmanTree::compress(string s)
{

    buildTree(frequencies(s));

    
}

string HuffmanTree::decode()
{
    return string();
}

void HuffmanTree::printFreq()
{
    // need to adjust to ensure only prints leaf nodes
     stack<TreeNode*> branches{};
    TreeNode* curr = root;

    while (!(branches.empty()) || curr)
    {
        // search the left side
        while (curr)
        {
            branches.push(curr);
            curr = curr->getNext(0);
        }

        curr = branches.top();

        if (curr)
        {
            curr->printNode();
        }

        branches.pop();

        curr = curr->getNext(1);
    }

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
            return n1->getVal() > n2->getVal();
        });

    return nodes;
}

void HuffmanTree::buildTree(vector<TreeNode*> nodes)
{
    // iterate through each value in the vector
    // if one value, tree is finished
    // if two values, create root node and tree is finished
    
    int count = nodes.size();

    if (!count) return; 

    if (count == 1)
    {
        root = nodes[0];
        return;
    }

    TreeNode* parent = nullptr;
    
    while (count - 1)
    {
        parent = new TreeNode();

        parent->setVal(nodes[count-1]->getVal() + nodes[count-2]->getVal());
        parent->setNext(nodes[count-1], 0); // set left
        parent->setNext(nodes[count-2], 1); // set right

        nodes.pop_back();
        nodes.pop_back();

        nodes.push_back(parent);

        // O(nlogn) avg
        sort(nodes.begin(), nodes.end(), [](TreeNode*& n1, TreeNode*& n2)
            {
                return n1->getVal() > n2->getVal();
            });

        --count;
    }

    root = parent;

}
