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
		if (!root) 
			return result;
		queue<TreeNode*> q;
		q.push(root);
		bool leftToRight = true;
		while (!q.empty())
		{
			vector<int> oneLevel;
			for (int i = q.size(); i > 0; --i)
			{
				TreeNode* tmp = q.front();
				q.pop();
				if (leftToRight)
				{
					oneLevel.push_back(tmp->val);
				}
				else
				{
					oneLevel.insert(oneLevel.begin(), tmp->val);
				}
				if (tmp->left)
					q.push(tmp->left);
				if (tmp->right)
					q.push(tmp->right);
			}
			leftToRight = !leftToRight;
			result.push_back(oneLevel);
		}
		return result;
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