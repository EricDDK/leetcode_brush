//Given a non - empty string s and a dictionary wordDict containing a list of non - empty words, add spaces in s to construct a sentence where each word is a valid dictionary word.Return all such possible sentences.
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
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_map<string, vector<string>> map;
		return wordBreakDFS(s, wordDict, map);
	}

	vector<string> wordBreakDFS(const string& s, vector<string>& wordDict, unordered_map<string, vector<string>>& map) {
		if (map.count(s))
			return map[s];
		if (s.empty())
			return{ "" };
		vector<string> res;
		for (string word : wordDict) {
			if (s.substr(0, word.size()) != word) 
				continue;
			vector<string> rem = wordBreakDFS(s.substr(word.size()), wordDict, map);
			for (string str : rem) {
				res.push_back(word + (str.empty() ? "" : " ") + str);
			}
		}
		return map[s] = res;
	}

private:

};

int main() {
	Solution* solution = new Solution;
	vector<string> input = { "cat", "cats", "and", "sand", "dog" };
	auto result = solution->wordBreak("catsanddog", input);
	delete(solution);
	system("pause");
	return 0;
}