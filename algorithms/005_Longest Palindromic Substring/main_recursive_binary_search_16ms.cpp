//Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.

#include "iostream"
#include <vector>
#include <unordered_map>
#include "windows.h"

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int length = s.size();
		if (length < 2)
		{
			return s;
		}
		int start = 0, maxLen = 0;
		for (int i = 0; i < length; ++i)
		{
			searchPalindrome(s, i, i, start, maxLen, length);
			searchPalindrome(s, i, i + 1, start, maxLen, length);
		}
		return s.substr(start, maxLen);
	}

	void searchPalindrome(string s, int left, int right, int &start, int &maxLen, int length)
	{
		while (left >= 0 && right < length && s[left] == s[right])
		{
			--left;
			++right;
		}

		if (right - left - 1 > maxLen)
		{
			start = left + 1;
			maxLen = right - left - 1;
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	string str = "babad";
	auto result = solution->longestPalindrome(str);
	delete solution;
	system("pause");
	return 0;
}
