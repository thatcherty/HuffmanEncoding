#include "BST.h"

BST::BST(TreeNode* head)
{
	this->head = head;
}

TreeNode* BST::top()
{
	return head;
}

void BST::add(int num)
{
	if (!head)
	{
		head = new TreeNode(num);
	}
	else
	{
		TreeNode* temp = head;
		TreeNode* prev = nullptr;
		bool exists = false;

		while (temp)
		{
			if (num == temp->getVal())
			{
				exists = true;
				break;
			}

			prev = temp;

			if (num < temp->getVal())
			{
				temp = temp->getNext(1);
			}
			else
			{
				temp = temp->getNext(0);
			}
		}

		if (!exists)
		{
			TreeNode* leaf = new TreeNode(num);
			prev->setNext(leaf, (num < prev->getVal()));
		}
	}
}

void BST::remove(int num) {
	TreeNode* parent = nullptr;
	TreeNode* curr = head;

	// Find node to delete and its parent
	while (curr && curr->getVal() != num) {
		parent = curr;
		bool goLeft = num < curr->getVal();
		curr = curr->getNext(goLeft);
	}
	if (!curr) return; // num not found

	TreeNode* L = curr->getNext(1);
	TreeNode* R = curr->getNext(0);

	// If two children 
	if (L && R) {
		TreeNode* succParent = curr;
		TreeNode* succ = R;
		while (succ->getNext(1)) { // find min in right subtree
			succParent = succ;
			succ = succ->getNext(1);
		}
		curr->setVal(succ->getVal()); // copy successor’s value

		// Delete successor (it has at most one child)
		TreeNode* succRight = succ->getNext(0);
		if (succParent->getNext(1) == succ)
			succParent->setNext(succRight, 1);
		else
			succParent->setNext(succRight, 0);

		delete succ;
		return;
	}

	// 0 or 1 child
	TreeNode* child = L ? L : R;

	// If deleting root
	if (!parent) {
		head = child;
	}
	else if (parent->getNext(1) == curr) {
		parent->setNext(child, 1);  // replace left
	}
	else {
		parent->setNext(child, 0); // replace right
	}

	delete curr;
}


std::string BST::search(int num)
{
	if (!head) return "";

	if (head->getVal() == num)
	{
		return "root";
	}

	std::string sol = "";

	TreeNode* temp = head;
	bool exists = false;

	while (temp)
	{
		if (num == temp->getVal())
		{
			exists = true;
			break;
		}

		if (num < temp->getVal())
		{
			sol += '0';
			temp = temp->getNext(1);
		}
		else 
		{
			sol += '1';
			temp = temp->getNext(0);
		}
	}

	if (exists)
	{
		return sol;
	}
	else
	{
		return "";
	}
	
}
void BST::in_order(TreeNode* root)
{
	stack<TreeNode*> branches{};
	TreeNode* curr = root;

	while (!(branches.empty()) || curr)
	{
		// search the left side
		while (curr)
		{
			branches.push(curr);
			curr = curr->getNext(1);
		}

		curr = branches.top();

		if (curr)
		{
			cout << curr->getVal() << " ";
		}

		branches.pop();

		curr = curr->getNext(0);
	}
}