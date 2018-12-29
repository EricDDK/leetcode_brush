//Given a singly linked list, determine if it is a palindrome.

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
	bool isPalindrome(ListNode* head) {
		stack<int> s1, s2;
		while (head)
		{
			s1.push(head->val);
			head = head->next;
		}
		int opacity = s1.size() / 2;
		for (int i = 0; i < opacity; ++i)
		{
			int tmp = s1.top();
			s1.pop();
			s2.push(tmp);
		}
		if (s1.size() != s2.size())
		{
			s1.pop();
		}
		for (int i = 0; i < opacity; ++i)
		{
			if (s1.top() != s2.top())
			{
				return false;
			}
			s1.pop();
			s2.pop();
		}
		return true;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> v = { 0,2,2,1 };
	ListNode* node = new ListNode(v[0]);
	ListNode* head = node;
	for (int i = 1; i < v.size(); ++i)
	{
		node->next = new ListNode(v[i]);
		node = node->next;
	}
	auto result = solution->isPalindrome(head);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}