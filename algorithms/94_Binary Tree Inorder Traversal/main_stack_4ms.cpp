//Given a string containing only digits, restore it by returning all possible valid IP address combinations.

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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> stack;
		TreeNode *tmp = root;
		while (tmp || !stack.empty())
		{
			while (tmp)
			{
				stack.push(tmp);
				tmp = tmp->left;
			}
			tmp = stack.top();
			stack.pop();
			result.push_back(tmp->val);
			tmp = tmp->right;
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	TreeNode* input = new TreeNode(1);
	input->left = NULL;
	input->right = new TreeNode(2);
	input->right->left = new TreeNode(3);
	auto result = solution->inorderTraversal(input);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}