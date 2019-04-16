//Given a binary tree and a sum, find all root - to - leaf paths where each path's sum equals the given sum.

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
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int>> res;
		vector<int> out;
		helper(root, sum, out, res);
		return res;
	}
	void helper(TreeNode* node, int sum, vector<int>& out, vector<vector<int>>& res) {
		if (!node) 
			return;
		out.push_back(node->val);
		if (sum == node->val && !node->left && !node->right) 
		{
			res.push_back(out);
		}
		helper(node->left, sum - node->val, out, res);
		helper(node->right, sum - node->val, out, res);
		out.pop_back();
	}
};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input = new TreeNode(5);
	input->left = new TreeNode(4);
	input->right = new TreeNode(8);
	input->left->left = new TreeNode(11);
	input->left->left->left = new TreeNode(7);
	input->left->left->right = new TreeNode(2);
	input->right->left = new TreeNode(13);
	input->right->right = new TreeNode(4);
	input->right->right->left = new TreeNode(5);
	input->right->right->right = new TreeNode(1);
	auto result = solution->pathSum(input, 1);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}