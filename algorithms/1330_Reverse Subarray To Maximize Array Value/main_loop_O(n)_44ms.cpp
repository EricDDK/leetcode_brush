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
	int maxValueAfterReverse(vector<int>& num) {
		int n = num.size();
		if (n == 1)
			return num[0];
		int sum = 0;
		for (int i = 1; i < n; i++)
			sum += abs(num[i] - num[i - 1]);
		int mx = 0;
		for (int i = 1; i < n - 1; i++)
		{
			mx = max(mx, abs(num[i + 1] - num[0]) - abs(num[i + 1] - num[i]));//单独考虑[1,i]翻转
			mx = max(mx, abs(num[n - 1] - num[i - 1]) - abs(num[i] - num[i - 1]));//单独考虑[i,n]区间翻转
		}
		int dp[4];
		for (int i = 0; i < 4; i++)
			dp[i] = -1e9;
		for (int i = 1; i < n; i++)
		{
			int x = abs(num[i] - num[i - 1]);
			dp[0] = max(dp[0], num[i] - num[i - 1] - x);
			dp[1] = max(dp[1], -num[i] - num[i - 1] - x);
			dp[2] = max(dp[2], num[i] + num[i - 1] - x);
			dp[3] = max(dp[3], -num[i] + num[i - 1] - x);
		}
		mx = max(mx, max(dp[0] + dp[3], dp[1] + dp[2]));
		return sum + mx;
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