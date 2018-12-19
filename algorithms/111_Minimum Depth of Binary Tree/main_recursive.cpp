//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
	int minDepth(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		if (!root->left && !root->right)
		{
			return 1;
		}
		if (!root->left)
		{
			return minDepth(root->right) + 1;
		}
		else if (!root->right)
		{
			return minDepth(root->left) + 1;
		}
		else
		{
			return 1 + min(minDepth(root->left), minDepth(root->right));
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input = new TreeNode(1);
	input->left = new TreeNode(2);
	input->right = new TreeNode(20);
	input->right->left = new TreeNode(15);
	input->right->right = new TreeNode(7);
	auto result = solution->minDepth(input);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
