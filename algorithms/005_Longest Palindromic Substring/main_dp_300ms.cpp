//Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
	string longestPalindrome(string s) {
		if (s.size() < 2)
			return s;
		vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
		int left = 0, right = 0, len = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			dp[i][i] = 1;
			for (int j = 0; j < i; ++j)
			{
				dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
				if (dp[j][i] && len < i - j + 1) {
					len = i - j + 1;
					left = j;
					right = i;
				}
			}
		}
		return s.substr(left, right - left + 1);
	}

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->longestPalindrome("cbbd");
	delete(solution);
	system("pause");
	return 0;
}