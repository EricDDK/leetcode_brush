//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the 
//next level and alternate between).

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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		zigzagLevelOrderBFS(root, result, 0);
		return result;
	}

	void zigzagLevelOrderBFS(TreeNode* root, vector<vector<int>> &result, int index) {
		if (!root)
			return;
		if (result.size() <= index)
			result.push_back({});
		if (index % 2 == 0)
			result[index].push_back(root->val);
		else {
			result[index].insert(result[index].begin(), root->val);
		}
		zigzagLevelOrderBFS(root->left, result, index+1);
		zigzagLevelOrderBFS(root->right, result, index + 1);
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
	auto result = solution->zigzagLevelOrder(input);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}