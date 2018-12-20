//Given a linked list, determine if it has a cycle in it.
//
//To represent a cycle in the given linked list, we use an integer pos which represents the position(0 - indexed) in the linked list where tail connects to.If pos is - 1, then there is no cycle in the linked list.

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
	bool hasCycle(ListNode *head) {
		if (!head)
		{
			return false;
		}
		ListNode* slow = head;
		ListNode* fast = head;
		while (true)
		{
			if (!slow->next || !fast->next || !fast->next->next)
			{
				return false;
			}
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				return true;
			}
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	ListNode* input = new ListNode(3);
	input->next = new ListNode(2);
	ListNode* pos = input->next;
	input->next->next = new ListNode(0);
	input->next->next->next = new ListNode(-4);
	input->next->next->next->next = pos;
	auto result = solution->hasCycle(input);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
