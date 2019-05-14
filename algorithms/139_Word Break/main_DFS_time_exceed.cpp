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
		int size = s.size();
		unordered_set<string> dict(wordDict.begin(), wordDict.end());
		if (size == 0)
			return true;
		if (dict.size() == 0)
			return false;

		return wordBreakDFS(s, dict, 0, size);
	}

	bool wordBreakDFS(const string& s, unordered_set<string>& set, int start, int size) {
		if (start >= size)
			return true;
		for (int i = start + 1; i <= size; ++i)
		{
			if (set.count(s.substr(start, i - start)))
			{
				if (wordBreakDFS(s, set, i, size))
				{
					start = i;
					return true;
				}
			}
		}
		return false;
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
	input = {"aaaa", "aaa"};
	result = solution->wordBreak("aaaaaaa", input);
	if (!result)
		throw;
	input = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
	result = solution->wordBreak(
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", 
		input);
	delete(solution);
	system("pause");
	return 0;
}