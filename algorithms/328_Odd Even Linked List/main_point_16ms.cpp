//Given a singly linked list, group all odd nodes together followed by the even nodes.Please note here we are talking about the 
//node number and not the value in the nodes.
//
//You should try to do it in place.The program should run in O(1) space complexity and O(nodes) time complexity.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include "windows.h"
#include <algorithm>
#include <stack>
#include <string>
#include <queue>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next) 
			return head;
		ListNode *pre = head, *cur = head->next;
		while (cur && cur->next)
		{
			ListNode *tmp = pre->next;
			pre->next = cur->next;
			cur->next = cur->next->next;
			pre->next->next = tmp;
			cur = cur->next;
			pre = pre->next;
		}
		return head;
	}
};

int main()
{
	Solution *solution = new Solution;
	vector<int> v = { 1,2,3,4,5 };
	ListNode* node = new ListNode(v[0]);
	ListNode* input = node;
	for (int row = 1; row < v.size(); ++row)
	{
		node->next = new ListNode(v[row]);
		node = node->next;
	}
	auto result = solution->oddEvenList(input);
	delete solution;
	system("pause");
	return 0;
}