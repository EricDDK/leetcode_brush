//Given a linked list, return the node where the cycle begins.If there is no cycle, return null.
//
//To represent a cycle in the given linked list, we use an integer pos which represents the position(0 - indexed) in the linked list where tail connects to.If pos is - 1, then there is no cycle in the linked list.
//
//Note: Do not modify the linked list.

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
	ListNode *detectCycle(ListNode *head) {
		unordered_set<ListNode*> map;
		int index = 0;
		while (head)
		{
			if (map.count(head))
				return head;
			else
				map.insert(map.begin(), head);
			index++;
			head = head->next;
		}
		return NULL;
	}
};

int main() {
	Solution* solution = new Solution;
	vector<int> v = { 3,2,0,-4 };
	ListNode* node = new ListNode(v[0]);
	ListNode* input = node;
	for (int row = 1; row < v.size(); ++row)
	{
		node->next = new ListNode(v[row]);
		node = node->next;
	}
	input->next->next->next->next = input->next;
	auto result = solution->detectCycle(input);
	delete(solution);
	system("pause");
	return 0;
}