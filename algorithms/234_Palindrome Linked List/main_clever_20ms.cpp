//Given a singly linked list, determine if it is a palindrome.

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
	ListNode* temp;
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
		{
			return true;
		}
		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *last = slow->next, *pre = head;
		while (last->next)
		{
			ListNode *tmp = last->next;
			last->next = tmp->next;
			tmp->next = slow->next;
			slow->next = tmp;
		}
		while (slow->next)
		{
			slow = slow->next;
			if (pre->val != slow->val)
				return false;
			pre = pre->next;
		}
		return true;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> v = { 0, 2, 2, 1, 4, 5, 6, 7, 8, 9, 10 };
	ListNode* node = new ListNode(v[0]);
	ListNode* head = node;
	for (int i = 1; i < v.size(); ++i)
	{
		node->next = new ListNode(v[i]);
		node = node->next;
	}
	auto result = solution->isPalindrome(head);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}