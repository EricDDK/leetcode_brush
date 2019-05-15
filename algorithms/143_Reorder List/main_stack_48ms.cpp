//Given a singly linked list L : L0¡úL1¡ú¡­¡úLn - 1¡úLn,
//reorder it to : L0¡úLn¡úL1¡úLn - 1¡úL2¡úLn - 2¡ú¡­
//
//You may not modify the values in the list's nodes, only nodes itself may be changed.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
	void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next)
			return;
		stack<ListNode*> s;
		ListNode* cur = head;
		while (cur)
		{
			s.push(cur);
			cur = cur->next;
		}
		cur = head;
		int midIndex = (s.size() - 1) / 2;
		while (midIndex-- > 0)
		{
			ListNode* t = s.top();
			s.pop();
			ListNode* next = cur->next;
			cur->next = t;
			t->next = next;
			cur = next;
		}
		s.top()->next = NULL;
	}
};

int main() {
	Solution* solution = new Solution;
	vector<int> v = { 1,2,3,4,5 };
	ListNode* node = new ListNode(v[0]);
	ListNode* input = node;
	for (int row = 1; row < v.size(); ++row)
	{
		node->next = new ListNode(v[row]);
		node = node->next;
	}
	/*auto result = */solution->reorderList(input);
	delete(solution);
	system("pause");
	return 0;
}