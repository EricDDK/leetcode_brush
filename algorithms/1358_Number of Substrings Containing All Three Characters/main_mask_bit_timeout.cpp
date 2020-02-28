//Given a string s consisting only of characters a, b and c.
//
//Return the number of substrings containing at least one occurrence of all these characters a, b and c.

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
#include <numeric>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Solution {
public:
	int numberOfSubstrings(string s) {
		int result = 0;
		for (int i = 0; i < s.size() - 2; ++i)
		{
			for (int j = i + 2; j < s.size(); ++j)
			{
				int mask = 7;
				for (int k = i; k <= j; ++k)
					mask &= (~(1 << (s[k] - 'a')));
				if (!mask)
				{
					result += s.size() - j;
					break;
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->numberOfSubstrings("abcabc");
	if (result != 10)
		throw;
	result = solution->numberOfSubstrings("ababbbc");
	if (result != 3)
		throw;
	delete solution;
	system("pause");
	return 0;
}