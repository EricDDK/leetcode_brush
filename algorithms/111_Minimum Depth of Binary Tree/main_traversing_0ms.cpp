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
		queue<TreeNode*> q;
		q.push(root);
		int index = 0;
		while (!q.empty())
		{
			index++;
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* rt = q.front();
				if (rt->left)
				{
					q.push(rt->left);
				}
				if (rt->right)
				{
					q.push(rt->right);
				}
				q.pop();
				if (!rt->left && !rt->right)
				{
					return index;
				}
			}
		}
		return -1;
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
