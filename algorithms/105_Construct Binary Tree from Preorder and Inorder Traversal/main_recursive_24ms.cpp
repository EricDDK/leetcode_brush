//Given preorder and inorder traversal of a tree, construct the binary tree.

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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder, inorder, 0, preorder.size() - 1, 0 , inorder.size() - 1);
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pLeft, int pRight, int iLeft, int iRight) {
		if (pLeft > pRight || iLeft > iRight)
			return NULL;
		int i = 0;
		for (i = iLeft; i <= iRight; ++i)
		{
			if (inorder[i] == preorder[pLeft])
			{
				break;
			}
		}
		TreeNode *cur = new TreeNode(preorder[pLeft]);
		cur->left = buildTree(preorder, inorder, pLeft + 1, pLeft + i - iLeft, iLeft, i - 1);
		cur->right = buildTree(preorder, inorder, pLeft + i - iLeft + 1, pRight, i + 1, iRight);
		return cur;
	}

};

int main()
{
	Solution* solution = new Solution;
	vector<int> input1 = {3,9,20,15,7};
	vector<int> input2 = {9,3,15,20,7};
	auto result = solution->buildTree(input1, input2);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}