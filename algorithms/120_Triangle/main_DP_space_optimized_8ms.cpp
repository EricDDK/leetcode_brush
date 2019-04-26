//Given a triangle, find the minimum path sum from top to bottom.Each step you may move to adjacent numbers on the row below.

#include <sstream>
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
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<int> dp(triangle.back());
		for (int i = triangle.size() - 2; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
			}
		}
		return dp[0];
	}

};

int main()
{
	Solution* solution = new Solution;
	vector<vector<int>> input = {
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3}
	};
	auto result = solution->minimumTotal(input);
	delete(solution);
	system("pause");
	return 0;
}