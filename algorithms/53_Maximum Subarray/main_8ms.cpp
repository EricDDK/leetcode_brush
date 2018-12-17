//Given an integer array nums, find the contiguous subarray(containing at least one number) which has the largest sum and return its sum.

#include "iostream"
#include <vector>
#include <unordered_map>
#include <map>
#include <hash_set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int res = INT_MIN, curSum = 0;
		for (int num : nums)
		{
			curSum = max(curSum + num, num);
			res = max(res, curSum);
		}
		return res;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	auto result = solution->maxSubArray(input);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
