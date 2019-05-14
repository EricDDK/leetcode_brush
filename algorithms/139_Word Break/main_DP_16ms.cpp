//Given a non - empty string s and a dictionary wordDict containing a list of non - empty words, determine if s can be segmented into a space - separated sequence of one or more dictionary words.
//
//Note:
//
//The same word in the dictionary may be reused multiple times in the segmentation.
//You may assume the dictionary does not contain duplicate words.

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
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> set(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.size() + 1);
		dp[0] = true;
		for (int i = 0; i <= s.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (dp[j] && set.count(s.substr(j, i - j)))
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp.back();
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<string> input = { "cats", "dog", "sand", "and", "cat" };
	auto result = solution->wordBreak("catsandog", input);
	if (result)
		throw;
	input = { "leet", "code" };
	result = solution->wordBreak("leetcode", input);
	if (!result)
		throw;
	input = { "aaaa", "aaa" };
	result = solution->wordBreak("aaaaaaa", input);
	if (!result)
		throw;
	input = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
	result = solution->wordBreak(
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
		input);
	if (result)
		throw;
	delete(solution);
	system("pause");
	return 0;
}