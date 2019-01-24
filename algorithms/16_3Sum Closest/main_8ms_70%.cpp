//Given an array nums of n integers and an integer target, find three integers in nums such that 
//the sum is closest to target.Return the sum of the three integers.You may assume that each input would have exactly one solution.

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
	int threeSumClosest(vector<int>& nums, int target) {
		int closest = nums[0] + nums[1] + nums[2];
		int diff = abs(closest - target);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			int left = i + 1, right = nums.size() - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				int newDiff = abs(sum - target);
				if (diff > newDiff)
				{
					diff = newDiff;
					closest = sum;
				}
				else if (sum < target)
				{
					left++;
				}
				else
				{
					right--;
				}
			}
		}
		return closest;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { -1, 2, 1, -4 };
	auto result = solution->threeSumClosest(input, 1);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}