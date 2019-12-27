//Find the length of the longest substring T of a given string(consists of lowercase letters only) 
//such that every character in T appears no less than k times.

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
	int longestSubstring(string s, int k) {
		if (s.empty())
			return 0;
		if (k <= 1)
			return k;
		int result = 0, n = s.size(), i = 0;
		while (i + k <= n)
		{
			int m[26] = { 0 }, mask = 0, max_idx = i;
			for (int j = i; j < n; ++j)
			{
				int t = s[j] - 'a';
				m[t]++;
				if (m[t] < k)
					mask |= (1 << t);
				else
					mask &= (~(1 << t));
				if (mask == 0)
				{
					result = max(result, j - i + 1);
					max_idx = j;
				}
			}
			i = max_idx + 1;
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->longestSubstring("aaabb", 3);
	if (result != 3)
		throw;
	result = solution->longestSubstring("ababbc", 2);
	if (result != 5)
		throw;
	result = solution->longestSubstring("a", 1);
	if (result != 1)
		throw;
	result = solution->longestSubstring("ababacb", 3);
	if (result != 0)
		throw;
	delete solution;
	system("pause");
	return 0;
}