//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		levelOrderBFS(root, result, 0);
		return result;
	}

	void levelOrderBFS(TreeNode* root, vector<vector<int>> &result, int index)
	{
		if (!root)
		{
			return;
		}
		if (result.size() <= index)
		{
			result.push_back({});
		}
		result[index].push_back(root->val);
		levelOrderBFS(root->left, result, index + 1);
		levelOrderBFS(root->right, result, index + 1);
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
	auto result = solution->levelOrder(input);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}