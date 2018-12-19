//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
//For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}

	TreeNode *sortedArrayToBST(vector<int> &num, int left, int right)
	{
		if (left > right)
		{
			return NULL;
		}
		int mid = (left + right) / 2;
		TreeNode* root = new TreeNode(num[mid]);
		root->left = sortedArrayToBST(num, left, mid-1);
		root->right = sortedArrayToBST(num, mid + 1, right);
		return root;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { -10, -3, 0, 5, 9 };
	auto result = solution->sortedArrayToBST(input);
	//cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
