#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(string s)
{
    compress(s);
}

void HuffmanTree::compress(string s)
{

    frequencies(s);
    getMapping();
    
}

string HuffmanTree::decode()
{
    return string();
}

void HuffmanTree::printMapping()
{
    //stack<TreeNode*> branches{};
    //TreeNode* curr = root;

    //while (!(branches.empty()) || curr)
    //{
    //    // search the left side
    //    while (curr)
    //    {
    //        branches.push(curr);

    //        // print leaf node
    //        if (!curr->getNext(0))
    //        {
    //            curr->printNode();
    //        }

    //        curr = curr->getNext(0);
    //    }

    //    curr = branches.top();

    //    branches.pop();

    //    curr = curr->getNext(1);
    //}

    for (auto& m : mapping)
    {
        cout << m.first << ": " << m.second << endl;
    }

}

// helper function
auto cmp = [](TreeNode* n1, TreeNode* n2) 
{
    return n1->getVal() > n2->getVal();
};


void HuffmanTree::frequencies(string s)
{
    unordered_map<char, int> freq{};

    // no need to sort
    priority_queue<TreeNode*, vector<TreeNode*>, decltype(cmp)> nodes(cmp);

    // O(s.length())
    for (int i = 0; i < s.length(); i++)
    {
        ++freq[s[i]];
    }

    // O(n = unique val in s)
    for (auto p : freq)
    {
        nodes.push(new TreeNode(p.second, p.first));
    }

    buildTree(nodes);
}

void HuffmanTree::getMapping()
{
    if (!root) return;

    string path = "";
    stack<string> pathSoFar{};
    stack<TreeNode*> branches{};
    TreeNode* curr = root;

    while (!branches.empty() || curr)
    {
        while (curr)
        {
            pathSoFar.push(path);
            branches.push(curr);
            path += "0";
            curr = curr->getNext(0);
        }

        path = pathSoFar.top();
        curr = branches.top();
        pathSoFar.pop();
        branches.pop();

        if (!curr->getNext(1) && !curr->getNext(0))
        {
            mapping[curr->getChar()] = path;
        }

        path += "1";
        curr = curr->getNext(1);
    }
}

template <typename cmp>
void HuffmanTree::buildTree(priority_queue<TreeNode*, vector<TreeNode*>, cmp>& nodes)
{
    // iterate through each value in the vector
    // if one value, tree is finished
    // if two values, create root node and tree is finished
    
    int count = nodes.size();

    if (!count) return; 

    if (count == 1)
    {
        root = nodes.top();
        return;
    }

    TreeNode* parent = nullptr;
    
    while (count - 1)
    {
        parent = new TreeNode();
        TreeNode* top = nodes.top();
        nodes.pop();
        TreeNode* sec = nodes.top();
        nodes.pop();

        parent->setVal(top->getVal() + sec->getVal());
        parent->setNext(top, 0); // set left
        parent->setNext(sec, 1); // set right

        nodes.push(parent);
        --count;
    }

    root = parent;

}
