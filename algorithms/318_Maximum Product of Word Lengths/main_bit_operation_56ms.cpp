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
		vector<int> v;
		int result = 0;
		for (auto& s : words)
		{
			int t = 0;
			for (auto& c : s)
			{
				t = t | (0x01 << (c - 'a'));
			}
			v.push_back(t);
		}
		int i, j;
		for (i = 0; i < words.size() - 1; ++i)
		{
			for (j = i + 1; j < words.size(); ++j)
			{
				if (hasNoCommon(v[i], v[j]))
				{
					int tmp = words[i].size() * words[j].size();
					result = max(result, tmp);
				}
			}
		}
		return result;
	}

	bool hasNoCommon(int a, int b)
	{
		for (index = 0; index < 26; ++index)
		{
			if (((a & 0x01) == 1) && ((b & 0x01) == 1))
			{
				return false;
			}
			a >>= 1;
			b >>= 1;
		}
		return true;
	}

	unsigned int index;
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