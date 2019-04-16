//Given a binary tree, determine if it is a valid binary search tree(BST).
//
//Assume a BST is defined as follows :
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
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

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}

	bool isValidBST(TreeNode* root, long min, long max)
	{
		if (!root) 
			return true;
		if (root->val <= min || root->val >= max)
			return false;
		return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
	}
};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input = new TreeNode(2);
	input->left = new TreeNode(1);
	input->right = new TreeNode(3);
	if (!solution->isValidBST(input))
		cout << "11111" << endl;
	input = new TreeNode(5);
	input->left = new TreeNode(1);
	input->right = new TreeNode(4);
	input->right->left = new TreeNode(3);
	input->right->right = new TreeNode(6);
	if (solution->isValidBST(input))
		cout << "222222" << endl;
	input = new TreeNode(1);
	input->left = new TreeNode(1);
	if (solution->isValidBST(input))
		cout << "33333" << endl;
	auto result = solution->isValidBST(input);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}