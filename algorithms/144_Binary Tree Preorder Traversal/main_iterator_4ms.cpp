//Given a binary tree, return the preorder traversal of its nodes' values.

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
	vector<int> preorderTraversal(TreeNode* root) {
		if (!root)
			return _result;
		stack<TreeNode*> s;
		TreeNode* node = root;
		while (node || !s.empty())
		{
			while (node)
			{
				_result.push_back(node->val);
				s.push(node);
				node = node->left;
			}
			if (!s.empty())
			{
				node = s.top();
				s.pop();
				node = node->right;
			}
		}
		return _result;
	}

private:
	vector<int> _result;
};

int main() {
	Solution* solution = new Solution;
	TreeNode* input = new TreeNode(1);
	input->right = new TreeNode(2);
	input->right->left = new TreeNode(3);
	auto result = solution->preorderTraversal(input);
	delete(solution);
	system("pause");
	return 0;
}