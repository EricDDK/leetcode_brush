//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

#include <sstream>
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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode* dummy = new ListNode(-1), *pre = dummy, * cur;
		dummy->next = head;
		while (pre->next)
		{
			cur = pre->next;
			while (cur->next && cur->next->val == cur->val)
			{
				cur = cur->next;
			}
			if (cur != pre->next)
				pre->next = cur->next;
			else
				pre = pre->next;
		}
		ListNode* result = dummy->next;
		delete dummy;
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> v = {1,2,3,3,4,4,5};
	ListNode* node = new ListNode(v[0]);
	ListNode* input = node;
	for (int i = 1; i < v.size(); ++i)
	{
		node->next = new ListNode(v[i]);
		node = node->next;
	}
	auto result = solution->deleteDuplicates(input);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}