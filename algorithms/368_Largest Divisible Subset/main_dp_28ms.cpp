//Given a non - negative integer n, count all numbers with unique digits, x, where 0 ¡Ü x < 10n.

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
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> dp(nums.size(), 0);
		vector<int> parent(nums.size(), 0);
		vector<int> result;
		int max = 0, maxIndex = 0;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			for (int j = i; j < nums.size(); ++j)
			{
				if (nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					parent[i] = j;
					if (max < dp[i])
					{
						max = dp[i];
						maxIndex = i;
					}
				}
			}
		}
		for (int i = 0; i < max; ++i)
		{
			result.push_back(nums[maxIndex]);
			maxIndex = parent[maxIndex];
		}
		return result;
	}
};

int main()
{
	Solution *solution = new Solution;
	auto result = solution->largestDivisibleSubset(vector<int>{1, 2, 3});
	if (result != vector<int>{1, 2} && result != vector<int>{1, 3})
		throw;
	result = solution->largestDivisibleSubset(vector<int>{1, 2, 4, 8});
	if (result != vector<int>{1, 2, 4, 8})
		throw;
	delete solution;
	system("pause");
	return 0;
}