//Given a string, find the length of the longest substring without repeating characters.

#include "iostream"
#include <vector>
#include <unordered_map>
#include "windows.h"

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0, left = -1, n = s.size();
		unordered_map<int, int> m;
		for (int i = 0; i < n; ++i) {
			if (m.count(s[i]) && m[s[i]] > left) {
				left = m[s[i]];
			}
			m[s[i]] = i;
			res = max(res, i - left);
		}
		return res;
	}
};

int main()
{
	Solution* solution = new Solution;
	string input = "abcabcbb";
	auto result = solution->lengthOfLongestSubstring(input);
	delete solution;
	system("pause");
	return 0;
}
