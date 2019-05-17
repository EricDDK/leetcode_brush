//Given a binary tree, return the postorder traversal of its nodes' values.

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
	vector<int> postorderTraversal(TreeNode* root) {
		if (!root)
			return _result;
		stack<TreeNode*> s;
		TreeNode* node = root;
		while (node || !s.empty())
		{
			if (node) {

				s.push(node);
				_result.insert(_result.begin(), node->val);
				node = node->right;
			}
			else 
			{
				TreeNode *t = s.top(); s.pop();
				node = t->left;
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
	auto result = solution->postorderTraversal(input);
	delete(solution);
	system("pause");
	return 0;
}