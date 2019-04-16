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
		set<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < int(nums.size() - 3); ++i) {
			for (int j = i + 1; j < int(nums.size() - 2); ++j) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int left = j + 1, right = nums.size() - 1;
				while (left < right) {
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						vector<int> out{ nums[i], nums[j], nums[left], nums[right] };
						res.insert(out);
						++left; --right;
					}
					else if (sum < target) ++left;
					else --right;
				}
			}
		}
		return vector<vector<int>>(res.begin(), res.end());
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