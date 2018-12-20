//Write a program to find the node at which the intersection of two singly linked lists begins.

#include "iostream"
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		int aLength = getLength(headA);
		int bLength = getLength(headB);
		int div = aLength - bLength;
		if (div >= 0)
		{
			while (div!=0)
			{
				headA = headA->next;
				div--;
			}
		}
		else
		{
			while (div != 0)
			{
				headB = headB->next;
				div++;
			}
		}
		while (headA && headB)
		{
			if (headA == headB)
			{
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return nullptr;
	}

	int getLength(ListNode* head)
	{
		int length = 0;
		if (!head)
		{
			return length;
		}
		while (head)
		{
			length++;
			head = head->next;
		}
		return length;
	}
};

int main()
{
	Solution* solution = new Solution;

	ListNode* input1 = new ListNode(4);
	input1->next = new ListNode(1);
	input1->next->next = new ListNode(8);
	input1->next->next->next = new ListNode(4);
	input1->next->next->next->next = new ListNode(5);

	ListNode* input2 = new ListNode(5);
	input2->next = new ListNode(0);
	input2->next->next = new ListNode(1);
	input2->next->next->next = new ListNode(8);
	input2->next->next->next->next = new ListNode(4);
	input2->next->next->next->next->next = new ListNode(5);

	auto result = solution->getIntersectionNode(input1, input2);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
