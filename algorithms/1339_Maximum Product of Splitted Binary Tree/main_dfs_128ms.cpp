//Given a binary tree root.Split the binary tree into two subtrees by removing 1 edge such that the product of the sums of the subtrees are maximized.
//
//Since the answer may be too large, return it modulo 10 ^ 9 + 7.

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
	int maxProduct(TreeNode* root) {
		total = dfs(root);
		dfs(root);
		return result % (int)(1e9 + 7);
	}

	int dfs(TreeNode* root) {
		if (!root)
			return 0;
		int sub = root->val + dfs(root->left) + dfs(root->right);
		result = max(result, sub * (total - sub));
		return sub;
	}

private:
	long long total;
	long long result;
};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input = new TreeNode(1);
	input->left = new TreeNode(2);
	input->right = new TreeNode(3);
	input->left->left = new TreeNode(4);
	input->left->right = new TreeNode(5);
	input->right->left = new TreeNode(6);
	auto result = solution->maxProduct(input);
	delete solution;
	system("pause");
	return 0;
}