//Invert a binary tree.

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
	TreeNode* invertTree(TreeNode* root) {
		if (!root)
		{
			return NULL;
		}
		TreeNode* tmp;
		tmp = root->right;
		root->right = root->left;
		root->left = tmp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input = new TreeNode(4);
	input->left = new TreeNode(2);
	input->right = new TreeNode(7);
	input->left->left = new TreeNode(1);
	input->left->right = new TreeNode(3);
	input->right->left = new TreeNode(6);
	input->right->right = new TreeNode(9);
	auto result = solution->invertTree(input);
	//count << result << endl;
	delete(solution);
	system("pause");
	return 0;
}