//Given a complete binary tree, count the number of nodes.
//
//Note:
//
//Definition of a complete binary tree from Wikipedia :
//In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.It can have between 1 and 2h nodes inclusive at the last level h.

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
	int countNodes(TreeNode* root) {
		TreeNode *left = root, *right = root;
		int hLeft = 0, hRight = 0;
		while (left)
		{
			++hLeft;
			left = left->left;
		}
		while (right)
		{
			++hRight;
			right = right->right;
		}
		if (hLeft == hRight)
			return pow(2, hLeft) - 1;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}

};

int main()
{
	Solution* solution = new Solution;
	TreeNode *input = new TreeNode(1);
	input->left = new TreeNode(2);
	input->right = new TreeNode(3);
	input->left->left = new TreeNode(4);
	input->left->right = new TreeNode(5);
	input->right->left = new TreeNode(6);
	if (solution->countNodes(input) != 6)
		throw;
	delete solution;
	system("pause");
	return 0;
}