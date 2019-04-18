//Given a binary tree, flatten it to a linked list in - place.

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
	void flatten(TreeNode* root) {
		if (!root)
			return;
		if (root->left)
			flatten(root->left);
		if (root->right)
			flatten(root->right);
		TreeNode *tmp = root->right;
		root->right = root->left;
		root->left = NULL;
		while (root->right)
			root = root->right;
		root->right = tmp;
	}

};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input = new TreeNode(1);
	input->left = new TreeNode(2);
	input->right = new TreeNode(5);
	input->left->left = new TreeNode(3);
	input->left->right = new TreeNode(4);
	input->right->right = new TreeNode(6);
	/*auto result = */solution->flatten(input);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}