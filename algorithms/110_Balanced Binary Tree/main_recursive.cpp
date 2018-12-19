//Given a binary tree, determine if it is height - balanced.
//
//For this problem, a height - balanced binary tree is defined as :
//
//a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

#include "iostream"
#include <vector>
#include <unordered_map>
#include <map>
#include <hash_set>
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
	bool isBalanced(TreeNode* root)
	{
		if (!root)
		{
			return true;
		}
		if (abs(getDepth(root->left) - getDepth(root->right)) <= 1)
		{
			return (isBalanced(root->left) && isBalanced(root->right));
		}
		else
		{
			return false;
		}
		return false;
	}

	int getDepth(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		return 1 + max(getDepth(root->left), getDepth(root->right));
	}
};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input = new TreeNode(3);
	input->left = new TreeNode(9);
	input->right = new TreeNode(20);
	input->right->left = new TreeNode(15);
	input->right->right = new TreeNode(7);
	auto result = solution->isBalanced(input);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
