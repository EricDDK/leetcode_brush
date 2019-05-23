//Given an input string, reverse the string word by word.

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
	string reverseWords(const string& s) {
		if (s.empty())
			return "";
		_vs.clear();
		string result;
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] != ' ')
			{
				start = i;
				end = i;
				while (end < s.size() && s[end++] != ' ')
				{

				}
				if (end == s.size() && s[end - 1] != ' ')
					end++;
				_vs.insert(_vs.begin(), s.substr(start, end - 1 - start));
				i = end - 1;
			}
		}
		for (int i = 0; i < _vs.size(); ++i)
		{
			if (!_vs.empty())
				result += (i != 0 ? " " + _vs[i] : _vs[i]);
		}
		return result;
	}

private:
	vector<string> _vs;

};

int main() {
	Solution* solution = new Solution;
	auto result = solution->reverseWords("a");
	if (solution->reverseWords("a") != "a")
		throw;
	if (solution->reverseWords("1 ") != "1")
		throw;
	if (solution->reverseWords("the sky is blue") != "blue is sky the")
		throw;
	if (solution->reverseWords("  hello world!  ") != "world! hello")
		throw;
	if (solution->reverseWords("a good   example") != "example good a")
		throw;
	delete(solution);
	system("pause");
	return 0;
}