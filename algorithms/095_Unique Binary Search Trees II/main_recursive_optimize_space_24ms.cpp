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
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return{};
		return *generateTreesDFS(1, n);
	}

	vector<TreeNode*> *generateTreesDFS(int start, int end) {
		vector<TreeNode *> *subTree = new vector<TreeNode *>();
		if (start > end)
		{
			subTree->push_back(NULL);
			return subTree;
		}
		for (int i = start; i <= end; i++)
		{
			vector<TreeNode*> *leftSubs = generateTreesDFS(start, i - 1);
			vector<TreeNode*> *rightSubs = generateTreesDFS(i + 1, end);
			for (int j = 0; j < leftSubs->size(); j++)
			{
				for (int k = 0; k < rightSubs->size(); k++)
				{
					TreeNode *node = new TreeNode(i);
					node->left = (*leftSubs)[j];
					node->right = (*rightSubs)[k];
					subTree->push_back(node);
				}
			}
		}
		return subTree;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->generateTrees(3);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}