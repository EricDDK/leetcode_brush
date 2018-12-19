//Given a binary tree and a sum, determine if the tree has a root - to - leaf path such that adding up all the values along the path equals the given sum.
//
//Note: A leaf is a node with no children.
//
//  Example :
//
//		  Given the below binary tree and sum = 22,

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
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)
		{
			return false;
		}
		if (!root->left && !root->right)
		{
			return sum == root->val ? true : false;
		}
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

int main()
{
	Solution* solution = new Solution;

	TreeNode* input = new TreeNode(1);
	input->left = new TreeNode(4);
	input->right = new TreeNode(8);
	input->left->left = new TreeNode(11);
	input->left->right = new TreeNode(NULL);
	input->right->left = new TreeNode(13);
	input->right->right = new TreeNode(4);
	input->left->left->left = new TreeNode(7);
	input->left->left->right = new TreeNode(2);
	input->right->right->right = new TreeNode(1);

	auto result = solution->hasPathSum(input,1);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
