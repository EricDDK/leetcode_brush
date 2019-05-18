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
		postorderTraversalDFS(root, _result);
		return _result;
	}

	void postorderTraversalDFS(TreeNode* root, vector<int>& result) {
		if (!root)
			return;
		if (root->left)
			postorderTraversalDFS(root->left, result);
		if (root->right)
			postorderTraversalDFS(root->right, result);
		if (root)
			result.push_back(root->val);
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