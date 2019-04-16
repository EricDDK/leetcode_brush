//You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example:
//
//Input : (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output : 7 -> 0 -> 8
//	 Explanation : 342 + 465 = 807.

#include "iostream"
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *res = new ListNode(-1);
		ListNode *cur = res;
		int carry = 0;
		while (l1 || l2) {
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;
			int sum = n1 + n2 + carry;
			carry = sum / 10;
			cur->next = new ListNode(sum % 10);
			cur = cur->next;
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		if (carry) cur->next = new ListNode(1);
		return res->next;
	}
};

int main()
{
	Solution* solution = new Solution;
	ListNode* l1 = new ListNode(2);
	ListNode* l2 = new ListNode(4);
	auto result = solution->addTwoNumbers(l1, l2);
	delete solution;
	system("pause");
	return 0;
}
