//Given a binary tree, return the bottom - up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],

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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result = {};
		build(root, result,0);
		reverse(result.begin(), result.end());
		return result;
	}

	void build(TreeNode* root, vector<vector<int> > &result,int index)
	{
		if (!root)
		{
			return;
		}
		if (result.size() == index)
		{
			result.push_back({});
		}
		result[index].push_back(root->val);
		if (root->left)
		{
			build(root->left, result, index+1);
		}
		if (root->right)
		{
			build(root->right, result, index + 1);
		}
	}

};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input1 = new TreeNode(3);
	input1->left = new TreeNode(9);
	input1->right = new TreeNode(20);
	input1->left->left = new TreeNode(NULL);
	input1->left->right = new TreeNode(NULL);
	input1->right->left = new TreeNode(15);
	input1->right->right = new TreeNode(7);
	auto result = solution->levelOrderBottom(input1);
	//cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
