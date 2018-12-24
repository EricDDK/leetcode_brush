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
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return nums[0];
		}
		if (n == 2)
		{
			return max(nums[0], nums[1]);
		}
		vector<int> v1 = vector<int>(nums.begin() + 1, nums.end());
		vector<int> v2 = vector<int>(nums.begin() + 2, nums.end());
		return max(rob(v1), nums[0] + rob(v2));
	}
};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	vector<int> input = { 1, 2, 3, 1, 5, 20, 17 };
	auto result = solution->rob(input);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
