//The thief has found himself a new place for his thievery again.There is only one entrance to this area, 
//called the "root." Besides the root, each house has one and only one parent house.After a tour, 
//the smart thief realized that "all houses in this place forms a binary tree".
//It will automatically contact the police if two directly - linked houses were broken into on the same night.
//
//Determine the maximum amount of money the thief can rob tonight without alerting the police.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include "windows.h"
#include <algorithm>
#include <stack>
#include <string>
#include <queue>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int rob(TreeNode* root) {
		if (!root)
			return 0;
		unordered_map<TreeNode*, int> m;
		return robDFS(root, m);
	}

	int robDFS(TreeNode* root, unordered_map<TreeNode*, int>& m)
	{
		if (!root)
			return 0;
		if (m.count(root))
			return m[root];
		int val = 0;
		if (root->left)
		{
			val += robDFS(root->left->left, m) + robDFS(root->left->right, m);
		}
		if (root->right)
		{
			val += robDFS(root->right->left, m) + robDFS(root->right->right, m);
		}
		val = max(val + root->val, robDFS(root->left, m) + robDFS(root->right, m));
		m[root] = val;
		return val;
	}

};

int main()
{
	Solution *solution = new Solution;
	TreeNode *input = new TreeNode(3);
	input->left = new TreeNode(2);
	input->right = new TreeNode(3);
	input->left->right = new TreeNode(3);
	input->right->right = new TreeNode(1);
	if (solution->rob(input) != 7)
		throw;
	input = new TreeNode(3);
	input->left = new TreeNode(4);
	input->right = new TreeNode(5);
	input->left->left = new TreeNode(1);
	input->left->right = new TreeNode(3);
	input->right->right = new TreeNode(1);
	if (solution->rob(input) != 9)
		throw;
	delete solution;
	system("pause");
	return 0;
}