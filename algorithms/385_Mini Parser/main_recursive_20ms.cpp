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

class NestedInteger {
public:
	// Constructor initializes an empty nested list.
	NestedInteger() {}
	// Constructor initializes a single integer.
	NestedInteger(int value) {}
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const { return true; }
	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const { return 0; }
	// Set this NestedInteger to hold a single integer.
	void setInteger(int value) {}
	// Set this NestedInteger to hold a nested list and adds a nested integer to it.
	void add(const NestedInteger &ni) {}
	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const { return vector<NestedInteger>(); }
};

class Solution {
public:
	NestedInteger deserialize(string s) {
		if (s.empty())
			return NestedInteger();
		if (s[0] != '[')
			return NestedInteger(stoi(s));
		if (s.size() <= 2) 
			return NestedInteger();
		NestedInteger result;
		int start = 1, cnt = 0;
		for (int i = 1; i < s.size(); ++i)
		{
			if (cnt == 0 && (s[i] == ',' || i == s.size() - 1))
			{
				result.add(deserialize(s.substr(start, i - start)));
				start = i + 1;
			}
			else if (s[i] == '[')
				++cnt;
			else if (s[i] == ']')
				--cnt;
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->deserialize("[123,[456,[789]]]");
	delete solution;
	system("pause");
	return 0;
}