//Given two binary trees, write a function to check if they are the same or not.
//
//Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
			return true;
		if (p == NULL || q == NULL) 
			return false;
		if (p->val == q->val)
		{
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		return false;
	}
};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input1 = new TreeNode(1);
	input1->left = new TreeNode(2);
	input1->left = new TreeNode(3);
	TreeNode* input2 = new TreeNode(1);
	input2->left = new TreeNode(2);
	input2->left = new TreeNode(3);
	auto result = solution->isSameTree(input1, input2);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
