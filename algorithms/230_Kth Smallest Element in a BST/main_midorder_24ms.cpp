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
		int cnt = 0;
		stack<TreeNode*> s;
		s.push(root);
		TreeNode *p = root;
		while (p || !s.empty())
		{
			while (p)
			{
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			++cnt;
			if (cnt == k)
				return p->val;
			p = p->right;
		}
		return 0;
	}

private:

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