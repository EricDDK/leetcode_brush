//Given an integer array nums, find the contiguous subarray(containing at least one number) which has the largest sum and return its sum.

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
	int maxSubArray(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		int result = dp[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
			result = max(dp[i], result);
		}
		return result;
	}

};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { -2,1,-3,4,-1,2,1,-5,4 };
	auto result = solution->maxSubArray(input);
	delete(solution);
	system("pause");
	return 0;
}