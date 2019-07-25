//Given a string array words, find the maximum value of length(word[i]) * length(word[j]) 
//where the two words do not share common letters.You may assume that each word will contain only lower case letters.
//If no such two words exist, return 0.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include "windows.h"
#include <algorithm>
#include <stack>
#include <string>
#include <queue>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Solution {
public:
	int maxProduct(vector<string>& words) {
		if (words.empty())
			return 0;
		vector<int> v(words.size(), 0);
		int result = 0, j = 0, i = 0;
		for (i = 0; i < words.size(); i++)
		{
			for (auto& c : words[i])
			{
				v[i] |= (0x01 << c - 'a');
			}
		}
		for (i = 0; i < words.size() - 1; ++i)
		{
			for (j = i + 1; j < words.size(); ++j)
			{
				if ((v[i] & v[j]) == 0)
				{
					result = max(result, (int)(words[i].size() * words[j].size()));
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution *solution = new Solution;
	vector<string> input;
	//
	input = {};
	if (solution->maxProduct(input) != 0)
		throw;
	input = { "abcw","baz","foo","bar","xtfn","abcdef" };
	if (solution->maxProduct(input) != 16)
		throw;
	input = { "a","ab","abc","d","cd","bcd","abcd" };
	if (solution->maxProduct(input) != 4)
		throw;
	input = { "a","aa","aaa","aaaa" };
	if (solution->maxProduct(input) != 0)
		throw;
	//
	delete solution;
	system("pause");
	return 0;
}