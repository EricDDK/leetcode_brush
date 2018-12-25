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
		stack<int> stack;
		while (head)
		{
			stack.push(head->val);
			head = head->next;
		}
		int size = stack.size();
		ListNode* l = new ListNode(-1);
		ListNode* result = l;
		for (int i = 0; i < size; i++)
		{
			l->next = new ListNode(stack.top());
			l = l->next;
			stack.pop();
		}
		return result->next;
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