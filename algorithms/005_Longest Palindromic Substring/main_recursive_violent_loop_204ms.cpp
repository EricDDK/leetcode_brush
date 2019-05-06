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
		int len = s.size();
		if (len < 2)
			return s;
		int start = 0, maxLen = 0;
		for (int i = 0; i < len - 1; ++i)
		{
			longestPalindromeDFS(s, start, maxLen, len, i);
		}
		return s.substr(start, maxLen + 1);
	}

	void longestPalindromeDFS(string &s, int &start, int &maxLen, int length, int index) {
		for (int i = 0; i < length - index; ++i)
		{
			if (maxLen < i && isPalindromic(s, index, index + i))
			{
				maxLen = i;
				start = index;
			}
		}
	}

	bool isPalindromic(string &s, int left, int right) {
		while (left <= right)
		{
			if (s[left] != s[right])
				return false;
			left++;
			right--;
		}
		return true;
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