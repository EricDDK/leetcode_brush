//Given a binary tree, find the lowest common ancestor(LCA) of two given nodes in the tree.
//
//According to the definition of LCA on Wikipedia : ¡°The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants(where we allow a node to be a descendant of itself).¡±
//
//Given the following binary tree : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]

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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || q == root || p == root)
			return root;
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (left && right)
			return root;
		return left ? left : right;
	}
};

int main()
{
	Solution* solution = new Solution;
	TreeNode *input = new TreeNode(3);
	input->left = new TreeNode(5);
	input->right = new TreeNode(1);
	input->left->left = new TreeNode(6);
	input->left->right = new TreeNode(2);
	input->right->left = new TreeNode(0);
	input->right->right = new TreeNode(8);
	input->left->right->left = new TreeNode(7);
	input->left->right->right = new TreeNode(4);
	if (solution->lowestCommonAncestor(input, input->left, input->right->left)->val != 3)
		throw;
	if (solution->lowestCommonAncestor(input, input->left, input->right)->val != 3)
		throw;
	if (solution->lowestCommonAncestor(input, input->left, input->left->right->right)->val != 5)
		throw;
	delete solution;
	system("pause");
	return 0;
}