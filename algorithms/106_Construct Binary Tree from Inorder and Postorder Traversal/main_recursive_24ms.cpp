//Given inorder and postorder traversal of a tree, construct the binary tree.

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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder, postorder, 0, inorder.size() - 1, 0 , postorder.size() - 1);
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int iLeft, int iRight, int pLeft, int pRight) {
		if (iLeft > iRight || pLeft > pRight)
			return NULL;
		TreeNode* cur = new TreeNode(postorder[pRight]);
		int i = 0;
		for (i = iLeft; i < inorder.size(); ++i)
		{
			if (inorder[i] == cur->val)
				break;
		}
		cur->left = buildTree(inorder, postorder, iLeft, i - 1, pLeft, pLeft + i - iLeft - 1);
		cur->right = buildTree(inorder, postorder, i + 1, iRight, pLeft + i - iLeft, pRight - 1);
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