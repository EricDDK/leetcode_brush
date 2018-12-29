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
	ListNode* temp;
	bool isPalindrome(ListNode* head) {
		temp = head;
		return check(head);
	}

	bool check(ListNode* p) {
		if (NULL == p) return true;
		bool isPal = check(p->next) & (temp->val == p->val);
		temp = temp->next;
		return isPal;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> v = { 0, 2, 2, 1 };
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