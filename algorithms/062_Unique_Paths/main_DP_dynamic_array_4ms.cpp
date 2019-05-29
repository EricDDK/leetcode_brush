//A peak element is an element that is greater than its neighbors.
//
//Given an input array nums, where nums[i] ¡Ù nums[i + 1], find a peak element and return its index.
//
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//You may imagine that nums[-1] = nums[n] = -¡Þ.

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
	int uniquePaths(int m, int n) {
		int **dp = new int*[m];
		int i, j;
		for (i = 0; i < m; ++i)
		{
			dp[i] = new int[n];
			for (j = 0; j < n; ++j)
			{
				dp[i][j] = 1;
			}
		}
		for (i = 1; i < m; ++i)
		{
			for (j = 1; j < n; ++j)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		int result = dp[m - 1][n - 1];
		for (i = 0; i < m; ++i)
		{
			delete[] dp[i];
		}
		delete[] dp;
		return result;
	}
};

int main() {
	Solution* solution = new Solution;
	vector<int> input = { 1,2,3,1 };
	if (solution->uniquePaths(3, 2) != 3)
		throw;
	delete(solution);
	system("pause");
	return 0;
}