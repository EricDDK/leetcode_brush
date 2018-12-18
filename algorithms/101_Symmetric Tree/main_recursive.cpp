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

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root)
	{
		if (!root)
			return true;
		return isSymmetric(root->left,root->right);
	}
	bool isSymmetric(TreeNode *left, TreeNode *right)
	{
		if (!left && !right)
		{
			return true;
		}
		if ( (!left && right) || (left && !right) || (left->val != right->val) )
		{
			return false;
		}
		return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}
};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input1 = new TreeNode(1);
	input1->left = new TreeNode(2);
	input1->right = new TreeNode(2);
	input1->left->left = new TreeNode(3);
	input1->left->right = new TreeNode(4);
	input1->right->left = new TreeNode(4);
	input1->right->right = new TreeNode(3);
	auto result = solution->isSymmetric(input1);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
