//Remove all elements from a linked list of integers that have value val.

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
	ListNode* removeElements(ListNode* head, int val) {
		if (!head)
		{
			return NULL;
		}
		head->next = removeElements(head->next, val);
		return head->val == val ? head->next : head;
	}
};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	vector<int> v = { 1, 1 };
	ListNode* node = new ListNode(v[0]);
	ListNode* head = node;
	for (int i = 1; i < v.size(); ++i)
	{
		node->next = new ListNode(v[i]);
		node = node->next;
	}
	auto result = solution->removeElements(head, 1);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}

//vector<int> v = { 1, 2, 6, 3, 4, 5, 6 };
//ListNode* node = new ListNode(v[0]);
//ListNode* head = node;
//for (int i = 1; i < v.size(); ++i)
//{
//	node->next = new ListNode(v[i]);
//	node = node->next;
//}