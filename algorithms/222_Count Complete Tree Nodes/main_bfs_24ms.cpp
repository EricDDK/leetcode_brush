//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

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
		if (!root)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		int result = 1;
		while (!q.empty())
		{
			TreeNode *tmp = q.front();
			q.pop();
			if (tmp->left)
			{
				result++;
				q.push(tmp->left);
			}
			if (tmp->right)
			{
				result++;
				q.push(tmp->right);
			}
		}
		return result;
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