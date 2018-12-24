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
		unordered_map<char, char> map;
		unordered_map<char, char> reverse_map;
		if (s.size() == t.size())
		{
			for (int i = 0; i < t.size(); ++i)
			{
				if (map.count(t[i]))
				{
					if (map[t[i]] != s[i])
					{
						return false;
					}
				}
				if (map.count(t[i]) || reverse_map.count(s[i]))
				{
					if (map[t[i]] != s[i] || reverse_map[s[i]] != t[i])
					{
						return false;
					}
				}
				map[t[i]] = s[i];
				reverse_map[s[i]] = t[i];
			}
			return true;
		}
		return false;
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