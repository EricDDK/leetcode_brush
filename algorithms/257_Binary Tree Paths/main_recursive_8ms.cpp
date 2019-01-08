//Given a binary tree, return all root - to - leaf paths.

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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (!root)
		{
			return result;
		}
		getString(root, to_string(root->val), result);
		return result;
	}

	void getString(TreeNode* root, string str, vector<string> &result)
	{
		if (!root->left && !root->right)
		{
			result.push_back(str);
			return;
		}
		if (root->left)
		{
			getString(root->left, str + "->" + to_string(root->left->val), result);
		}
		if (root->right)
		{
			getString(root->right, str + "->" + to_string(root->right->val), result);
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input = new TreeNode(1);
	input->left = new TreeNode(2);
	input->right = new TreeNode(3);
	input->left->right = new TreeNode(5);
	auto result = solution->binaryTreePaths(input);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}