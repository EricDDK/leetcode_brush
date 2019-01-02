//Lowest Common Ancestor of a Binary Search Tree

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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root)
		{
			return NULL;
		}
		if (root->val > max(p->val,q->val))
		{
			return lowestCommonAncestor(root->left,p,q);
		}
		else if (root->val < min(p->val, q->val))
		{
			return lowestCommonAncestor(root->right, p, q);
		}
		else
		{
			return root;
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> v = { 6, 2, 8, 0, 4, 7, 9, NULL, NULL, 3, 5 };
	TreeNode* input = new TreeNode(6);
	input->left = new TreeNode(2);
	input->right = new TreeNode(8);
	input->left->left = new TreeNode(0);
	input->left->right = new TreeNode(4);
	input->left->right->left = new TreeNode(3);
	input->left->right->right = new TreeNode(5);
	input->right->left = new TreeNode(7);
	input->right->right = new TreeNode(9);
	auto result = solution->lowestCommonAncestor(input, input->left, input->right);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}