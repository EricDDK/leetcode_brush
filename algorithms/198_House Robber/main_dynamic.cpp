//Given an array, rotate the array to the right by k steps, where k is non - negative.

#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
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
	int rob(vector<int>& nums) {
		if (nums.size() <= 1)
			return nums.empty() ? 0 : nums[0];
		vector<int> dp = { nums[0], max(nums[0], nums[1]) };
		for (int i = 2; i < nums.size(); ++i)
		{
			dp.push_back(max(nums[i] + dp[i - 2], dp[i - 1]));
		}
		return dp.back();
	}
};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	vector<int> input = { 1, 2, 3, 1, 5, 20, 0 };
	auto result = solution->rob(input);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
