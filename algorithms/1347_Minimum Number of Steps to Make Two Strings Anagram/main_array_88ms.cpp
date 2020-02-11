//Given two equal - size strings s and t.In one step you can choose any character of t and replace it with another character.
//
//Return the minimum number of steps to make t an anagram of s.
//
//An Anagram of a string is a string that contains the same characters with a different(or the same) ordering.

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

class Solution {
public:
	int minSteps(string s, string t) {
		vector<int> cnt1(26);
		vector<int> cnt2(26);
		for (int i = 0; i<s.size(); i++) 
		{
			cnt1[s[i] - 'a'] += 1;
		}
		for (int i = 0; i<t.size(); i++) 
		{
			cnt2[t[i] - 'a'] += 1;
		}
		int ans = 0;
		for (int i = 0; i<26; i++) 
		{
			if (cnt1[i]>cnt2[i]) 
			{
				ans += cnt1[i] - cnt2[i];
			}
		}
		return ans;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->minSteps("bab", "aba");
	if (result != 1)
		throw;
	result = solution->minSteps("leetcode", "practice");
	if (result != 5)
		throw;
	result = solution->minSteps("anagram", "mangaar");
	if (result != 0)
		throw;
	result = solution->minSteps("xxyyzz", "xxyyzz");
	if (result != 0)
		throw;
	result = solution->minSteps("friend", "family");
	if (result != 4)
		throw;
	system("pause");
	return 0;
}