//Given a binary tree containing digits from 0 - 9 only, each root - to - leaf path could represent a number.
//
//An example is the root - to - leaf path 1->2->3 which represents the number 123.
//
//Find the total sum of all root - to - leaf numbers.
//
//Note: A leaf is a node with no children.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
	int sumNumbers(TreeNode* root) {
		if (!root)
			return 0;
		stack<TreeNode*> s;
		s.push(root);
		int result = 0;
		while (!s.empty())
		{
			TreeNode* tmp = s.top();
			s.pop();
			if (!tmp->left && !tmp->right)
				result += tmp->val;
			if (tmp->left)
			{
				tmp->left->val += tmp->val * 10;
				s.push(tmp->left);
			}
			if (tmp->right)
			{
				tmp->right->val += tmp->val * 10;
				s.push(tmp->right);
			}
		}
		return result;
	}

};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input = new TreeNode(4);
	input->left = new TreeNode(9);
	input->right = new TreeNode(0);
	input->left->left = new TreeNode(5);
	input->left->right = new TreeNode(1);
	auto result = solution->sumNumbers(input);
	delete(solution);
	system("pause");
	return 0;
}