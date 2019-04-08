//Given a string containing only digits, restore it by returning all possible valid IP address combinations.

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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		inorderTraversalDFS(root, result);
		return result;
	}

	void inorderTraversalDFS(TreeNode* root, vector<int> &result) {
		if (!root) 
			return;
		if (root->left)
			inorderTraversalDFS(root->left, result);
		result.push_back(root->val);
		if (root->right)
			inorderTraversalDFS(root->right, result);
	}

};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input = new TreeNode(1);
	input->left = NULL;
	input->right = new TreeNode(2);
	input->right->left = new TreeNode(3);
	auto result = solution->inorderTraversal(input);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}