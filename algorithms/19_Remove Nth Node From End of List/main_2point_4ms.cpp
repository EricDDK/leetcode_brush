//Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums 
//such that a + b + c + d = target ? Find all unique quadruplets in the array which gives the sum of target.

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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head || !head->next)
		{
			return NULL;
		}
		ListNode* left = head;
		ListNode* right = head;
		for (int i = 0; i < n; ++i)
		{
			right = right->next;
		}
		if (!right)
		{
			return head->next;
		}
		while (right->next)
		{
			left = left->next;
			right = right->next;
		}
		ListNode *tmp = left->next;
		left->next = left->next->next;
		delete tmp;
		return head;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> v = { 1 };
	ListNode* node = new ListNode(v[0]);
	ListNode* input = node;
	for (int i = 1; i < v.size(); ++i)
	{
		node->next = new ListNode(v[i]);
		node = node->next;
	}
	auto result = solution->removeNthFromEnd(input, 2);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}