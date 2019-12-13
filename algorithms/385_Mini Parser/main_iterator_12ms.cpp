//Given a nested list of integers represented as a string, implement a parser to deserialize it.
//
//Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//
//Note: You may assume that the string is well - formed :
//
//	String is non - empty.
//	String does not contain white spaces.
//	String contains only digits 0 - 9, [, -, , ].

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
		stack<NestedInteger> st;
		int start = 1;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '[')
			{
				st.push(NestedInteger());
				start = i + 1;
			}
			else if (s[i] == ',' || s[i] == ']')
			{
				if (i > start) {
					st.top().add(NestedInteger(stoi(s.substr(start, i - start))));
				}
				start = i + 1;
				if (s[i] == ']')
				{
					if (st.size() > 1)
					{
						NestedInteger t = st.top();
						st.pop();
						st.top().add(t);
					}
				}
			}
		}
		return st.top();
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