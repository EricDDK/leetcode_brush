/*Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the
order of characters.No two characters may map to the same character but a character may map to itself.*/

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

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int cs[128] = { 0 }, ct[128] = { 0 };
		for (int i = 0; i<s.size(); i++)
		{
			if (cs[s[i]] != ct[t[i]]) return false;
			else if (!cs[s[i]]) //only record once
			{
				cs[s[i]] = i + 1;
				ct[t[i]] = i + 1;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	auto result = solution->isIsomorphic("egg", "add");
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}