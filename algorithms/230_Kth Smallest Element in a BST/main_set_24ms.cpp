//Given an integer array of size n, find all elements that appear more than n / 3 times.
//
//Note: The algorithm should run in linear time and in O(1) space.

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
	int kthSmallest(TreeNode* root, int k) {
		if (!root)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			auto tmp = q.front();
			q.pop();
			if (tmp->left)
			{
				q.push(tmp->left);
			}
			if (tmp->right)
			{
				q.push(tmp->right);
			}
			s.insert(tmp->val);
		}
		auto iter = s.begin();
		for (int i = 0; i < k - 1; ++i)
		{
			iter++;
		}
		return *iter;
	}

private:
	set<int> s;
};

int main()
{
	Solution* solution = new Solution;
	TreeNode *input = new TreeNode(3);
	input->left = new TreeNode(1);
	input->right = new TreeNode(4);
	input->left->right = new TreeNode(2);
	if (solution->kthSmallest(input, 1) != 1)
		throw;

	input = new TreeNode(5);
	input->left = new TreeNode(3);
	input->right = new TreeNode(6);
	input->left->left = new TreeNode(2);
	input->left->right = new TreeNode(4);
	input->left->left = new TreeNode(1);
	if (solution->kthSmallest(input, 3) != 3)
		throw;
	delete solution;
	system("pause");
	return 0;
}