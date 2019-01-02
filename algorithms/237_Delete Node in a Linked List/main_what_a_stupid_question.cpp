//Lowest Common Ancestor of a Binary Search Tree

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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		if (node == NULL) return;
		ListNode *tmp = node->next;
		node->val = tmp->val;
		node->next = tmp->next;
		delete tmp;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> v = { 4, 5, 1, 9 };
	ListNode* node = new ListNode(v[0]);
	ListNode* input = node;
	for (int i = 1; i < v.size(); ++i)
	{
		node->next = new ListNode(v[i]);
		node = node->next;
	}
	auto result = solution->deleteNode(input);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}