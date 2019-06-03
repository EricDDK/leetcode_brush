//Implement an iterator over a binary search tree(BST).Your iterator will be initialized with the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		Oreder(root);
	}

	void Oreder(TreeNode* root) {
		if (!root)
			return;
		if (root->left)
			Oreder(root->left);
		_queue.push(root->val);
		if (root->right)
			Oreder(root->right);
	}

	/** @return the next smallest number */
	int next() {
		int result = _queue.front();
		_queue.pop();
		return result;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !_queue.empty();
	}

private:
	queue<int> _queue;
};

int main() {
	TreeNode *input = new TreeNode(7);
	input->left = new TreeNode(3);
	input->right = new TreeNode(15);
	input->right->left = new TreeNode(9);
	input->right->right = new TreeNode(20);
	BSTIterator iterator = BSTIterator(input);

	system("pause");
	return 0;
}