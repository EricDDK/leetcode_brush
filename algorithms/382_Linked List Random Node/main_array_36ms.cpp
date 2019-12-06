//Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
//
//Follow up :
//What if the linked list is extremely large and its length is unknown to you ? Could you solve this efficiently without using extra space ?

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
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		while (head != NULL)
		{
			v.push_back(head->val);
			head = head->next;
		}
	}

	/** Returns a random node's value. */
	int getRandom() {
		return v[rand() % v.size()];
	}
private:
	vector<int> v;
};

int main()
{
	//Solution *solution = new Solution;
	//delete solution;
	system("pause");
	return 0;
}