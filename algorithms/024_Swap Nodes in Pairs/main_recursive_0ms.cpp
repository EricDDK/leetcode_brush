//Given a linked list, swap every two adjacent nodes and return its head.

#include<sstream>
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
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* tmp = head->next;
		head->next = swapPairs(tmp->next);
		tmp->next = head;
		return tmp;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> v = { 1, 2, 3, 4 };
	ListNode* node = new ListNode(v[0]);
	ListNode* input = node;
	for (int i = 1; i < v.size(); ++i)
	{
		node->next = new ListNode(v[i]);
		node = node->next;
	}
	auto result = solution->swapPairs(input);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}