//Given a sorted linked list, delete all duplicates such that each element appear only once.

#include "iostream"
#include <vector>
#include <unordered_map>
#include <map>
#include <hash_set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* start = head;
		while (start && start->next)
		{
			if (start->val == start->next->val)
			{
				ListNode* temp = start->next;
				start->next = start->next->next;
				delete temp;
			}
			else
			{
				start = start->next;
			}
		}
		return head;
	}
};

int main()
{
	Solution* solution = new Solution;
	ListNode * input = new ListNode(1);
	input->next = new ListNode(1);
	input->next->next = new ListNode(2);
	input->next->next->next = new ListNode(3);
	input->next->next->next->next = new ListNode(3);
	auto result = solution->deleteDuplicates(input);
	cout << result << endl;
	delete solution;
	while (input)
	{
		input->val = NULL;
		input = input->next;
	}
	while (result)
	{
		result->val = NULL;
		result = result->next;
	}
	system("pause");
	return 0;
}
