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
		vector<vector<int>> result;
		if (!root)
			return result;
		queue<TreeNode*> q;
		q.push(root);
		int index = 0;
		while (!q.empty())
		{
			vector<int> level;
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* tmp = q.front();
				q.pop();
				level.push_back(tmp->val);
				if (tmp->left)
				{
					q.push(tmp->left);
				}
				if (tmp->right)
				{
					q.push(tmp->right);
				}
			}
			result.insert(result.begin(),level);
		}
		return result;
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
