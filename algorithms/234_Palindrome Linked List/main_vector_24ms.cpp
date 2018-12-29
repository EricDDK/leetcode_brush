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
		if (!head)
		{
			return true;
		}
		vector<int> v;
		int index = 0;
		while (head)
		{
			v.insert(v.begin() + (index++), head->val);
			head = head->next;
		}
		int left = 0, right = index - 1;
		while (left < right)
		{
			if (v[left] != v[right])
			{
				return false;
			}
			left++; right--;
		}
		return true;
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