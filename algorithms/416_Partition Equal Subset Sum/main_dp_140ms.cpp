//Given a non - empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
//Note:
//
//Each of the array element will not exceed 100.
//The array size will not exceed 200.

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
	bool canPartition(vector<int>& nums) {
		long long sum = 0;
		for (auto& n : nums)
		{
			sum += n;
		}
		if (sum % 2 == 0)
		{
			int target = sum / 2;
			vector<bool> dp(target + 1, false);
			dp[0] = true;
			for (auto& n : nums)
			{
				for (int i = target; i >= n; --i)
				{
					dp[i] = dp[i] || dp[i - n];
				}
			}
			return dp[target];
		}
		return false;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->canPartition(vector<int>{1, 5, 11, 5});
	if (!result)
		throw;
	result = solution->canPartition(vector<int>{1, 2, 3, 5});
	if (result)
		throw;
	result = solution->canPartition(vector<int>{23, 13, 11, 7, 6, 5, 5});
	if (!result)
		throw;
	delete solution;
	system("pause");
	return 0;
}