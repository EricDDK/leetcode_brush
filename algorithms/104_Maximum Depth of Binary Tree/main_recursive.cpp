//Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
//
//For example, this binary tree[1, 2, 2, 3, 4, 4, 3] is symmetric :

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
	int maxDepth(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input1 = new TreeNode(1);
	input1->left = new TreeNode(2);
	/*input1->right = new TreeNode(20);
	input1->left->left = new TreeNode(NULL);
	input1->left->right = new TreeNode(NULL);
	input1->right->left = new TreeNode(5);
	input1->right->right = new TreeNode(7);*/
	auto result = solution->maxDepth(input1);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
