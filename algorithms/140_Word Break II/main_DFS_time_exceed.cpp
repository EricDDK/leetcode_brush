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
		vector<string> result;
		unordered_set<string> set(wordDict.begin(), wordDict.end());
		string out;
		wordBreakDFS(s, set, out, 0, s.size(), result);
		return result;
	}

	void wordBreakDFS(const string& s, unordered_set<string>& set, string out, int start, int size, vector<string>& result) {
		if (start >= size) {
			result.push_back(out);
			return;
		}
		for (int i = start + 1; i <= size; ++i) {
			std::string str = s.substr(start, i - start);
			if (set.count(str)) {
				wordBreakDFS(s, set, out + (out.empty() ? (str) : (' ' + (str))), i, size, result);
			}
		}
		return;
	}

};

int main() {
	Solution* solution = new Solution;
	vector<string> input = { "cat", "cats", "and", "sand", "dog" };
	auto result = solution->wordBreak("catsanddog", input);
	delete(solution);
	system("pause");
	return 0;
}