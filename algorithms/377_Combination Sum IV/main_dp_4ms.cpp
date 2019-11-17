//Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

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
	int combinationSum4(vector<int>& nums, int target) {
		vector<unsigned int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= target; ++i)
		{
			for (auto &n : nums)
			{
				if (i >= n)
				{
					dp[i] += dp[i - n];
				}
			}
		}
		return dp.back();
	}
};

int main()
{
	Solution *solution = new Solution;
	auto result = solution->combinationSum4(vector<int>{1, 2, 3}, 4);
	if (result != 7)
		throw;
	/*result = solution->combinationSum4(vector<int>{4,2,1}, 32);
	if (result != 7)
		throw;*/
	delete solution;
	system("pause");
	return 0;
}