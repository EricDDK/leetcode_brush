//Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.

#include<sstream>
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
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		if (nums.empty() || nums.back() < 0 || nums.front() > 0) 
			return {};
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > 0) 
				break;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int target = 0 - nums[i];
			int j = i + 1, k = nums.size() - 1;
			while (j < k)
			{
				if (nums[j] + nums[k] == target)
				{
					result.push_back({ nums[i], nums[j], nums[k] });
					while (j < k && nums[j] == nums[j + 1]) 
						++j;
					while (j < k && nums[k] == nums[k - 1]) 
						--k;
					++j; --k;
				}
				else if (nums[j] + nums[k] < target)
				{
					++j;
				}
				else
				{
					--k;
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { -1, 0, 1, 2, -1, -4 };
	auto result = solution->threeSum(input);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}