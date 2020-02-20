// You are given an integer array nums.The value of this array is defined as the sum of | nums[i] - nums[i + 1] | for all 0 <= i < nums.length - 1.
//
//	You are allowed to select any subarray of the given array and reverse it.You can perform this operation only once.
//
//	Find maximum possible value of the final array.

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
#include <numeric>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Solution {
public:
	int maxValueAfterReverse(vector<int>& nums) {
		int n = nums.size();
		int left = 0, right = n - 1;
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i; j < n; ++j)
			{
				int l = (i == 0 ? 0 : abs(nums[i] - nums[i - 1]));
				int r = (j == n - 1 ? 0 : abs(nums[j] - nums[j + 1]));
				int sum1 = l + r;
				l = (i == 0 ? 0 : abs(nums[j] - nums[i - 1]));
				r = (j == n - 1 ? 0 : abs(nums[i] - nums[j + 1]));
				int sum2 = l + r;
				if (sum2 - sum1 >= sum)
				{
					sum = sum2 - sum1;
					left = i; right = j;
				}
			}
		}
		reverse(nums.begin() + left, nums.begin() + right + 1);
		int result = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			result += abs(nums[i] - nums[i + 1]);
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->maxValueAfterReverse(vector<int>{ 2, 3, 1, 5, 4 });
	if (result != 10)
		throw;
	result = solution->maxValueAfterReverse(vector<int>{2, 4, 9, 24, 2, 1, 10});
	if (result != 68)
		throw;
	delete solution;
	system("pause");
	return 0;
}