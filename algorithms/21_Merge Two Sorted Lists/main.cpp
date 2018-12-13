//Merge two sorted linked lists and return it as a new list.The new list should be made by splicing together the nodes of the first two lists.

#include "iostream"
#include <vector>
#include <unordered_map>
#include "windows.h"
#include "algorithm"
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* l3 = new ListNode(0);
		ListNode* res = l3;
		while (l1 && l2)
		{
			int val1 = l1->val;
			int val2 = l2->val;
			if (val1 <= val2)
			{
				l3->next = new ListNode(val1);
				l1 = l1->next;
				l3 = l3->next;
			}
			else
			{
				l3->next = new ListNode(val2);
				l2 = l2->next;
				l3 = l3->next;
			}
		}
		while (l1)
		{
			l3->next = new ListNode(l1->val);
			l1 = l1->next;
			l3 = l3->next;
		}
		while (l2)
		{
			l3->next = new ListNode(l2->val);
			l2 = l2->next;
			l3 = l3->next;
		}
		return res->next;
	}
};

int main()
{
	Solution* solution = new Solution;
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);
	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	auto result = solution->mergeTwoLists(l1, l2);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
