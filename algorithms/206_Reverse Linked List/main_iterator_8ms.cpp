//Reverse a singly linked list.

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
	ListNode* reverseList(ListNode* head) {
		if (!head) 
			return head;
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *cur = head;
		while (cur->next)
		{
			ListNode *tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = dummy->next;
			dummy->next = tmp;
		}
		return dummy->next;
	}
};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	vector<int> v = { 1,2,3,4,5 };
	ListNode* node = new ListNode(v[0]);
	ListNode* head = node;
	for (int i = 1; i < v.size(); ++i)
	{
		node->next = new ListNode(v[i]);
		node = node->next;
	}
	auto result = solution->reverseList(head);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}