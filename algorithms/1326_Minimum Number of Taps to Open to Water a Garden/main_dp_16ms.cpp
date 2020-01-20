//There is a one - dimensional garden on the x - axis.The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).
//
//There are n + 1 taps located at points[0, 1, ..., n] in the garden.
//
//Given an integer n and an integer array ranges of length n + 1 where ranges[i](0 - indexed) means the i - th tap can water the area[i - ranges[i], i + ranges[i]] if it was open.
//
//Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.

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
	int minTaps(int n, vector<int>& ranges) {
		vector<int> dp(n + 1);
		for (int i = 0; i < ranges.size(); ++i)
		{
			int left = max(0, i - ranges[i]);
			int right = min(n, i + ranges[i]);
			dp[left] = max(dp[left], right);
		}
		for (int i = 1; i < ranges.size(); ++i)
		{
			dp[i] = max(dp[i - 1], dp[i]);
		}
		int result = 0;
		int i = 0;
		while (i < n)
		{
			if (i == dp[i])
				return -1;
			i = dp[i];
			++result;
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->minTaps(5, vector<int>{3, 4, 1, 1, 0, 0});
	if (result != 1)
		throw;
	result = solution->minTaps(3, vector<int>{0, 0, 0, 0});
	if (result != -1)
		throw;
	result = solution->minTaps(7, vector<int>{1, 2, 1, 0, 2, 1, 0, 1});
	if (result != 3)
		throw;
	result = solution->minTaps(8, vector<int>{4, 0, 0, 0, 0, 0, 0, 0, 4});
	if (result != 2)
		throw;
	result = solution->minTaps(8, vector<int>{4, 0, 0, 0, 4, 0, 0, 0, 4});
	if (result != 1)
		throw;
	delete solution;
	system("pause");
	return 0;
}