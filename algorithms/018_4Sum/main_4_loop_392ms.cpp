//Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums 
//such that a + b + c + d = target ? Find all unique quadruplets in the array which gives the sum of target.

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
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		set<vector<int>> result;
		sort(nums.begin(), nums.end());
		//if (nums.empty() || nums.back() > target || nums.front() < target || nums.size() < 4)
		//{
		//	return {};
		//}
		for (int i = 0; (i < nums.size()); ++i)
		{
			for (int j = i + 1; (j < nums.size()); ++j)
			{
				for (int k = j + 1; (k < nums.size()); ++k)
				{
					for (int l = k + 1; (l < nums.size()); ++l)
					{
						if (nums[i] + nums[j] + nums[k] + nums[l] == target )
						{
							result.insert({ nums[i], nums[j], nums[k], nums[l] });
						}
					}
				}
			}
		}
		return vector<vector<int>>(result.begin(), result.end());
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 1, -2, -5, -4, -3, 3, 3, 5 };
	auto result = solution->fourSum(input, 11);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}