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
	Solution(vector<int>& nums) {
		v = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return v;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> res = v;
		for (int i = 0; i < res.size(); ++i) 
		{
			int t = i + rand() % (res.size() - i);
			swap(res[i], res[t]);
		}
		return res;
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