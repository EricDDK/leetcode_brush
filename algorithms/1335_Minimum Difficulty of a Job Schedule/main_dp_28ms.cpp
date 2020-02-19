//Given an array of integers arr, replace each element with its rank.
//
//The rank represents how large the element is.The rank has the following rules :
//
//Rank is an integer starting from 1.
//The larger the element, the larger the rank.If two elements are equal, their rank must be the same.
//Rank should be as small as possible.

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

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Solution {
public:
	int minDifficulty(vector<int>& jobDifficulty, int d) {
		int n = jobDifficulty.size();
		if (n < d)
			return -1;
		vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX / 2));
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int k = 1; k <= d; ++k)
			{
				int md = 0;
				for (int j = i - 1; j >= k - 1; --j)
				{
					md = max(md, jobDifficulty[j]);
					dp[i][k] = min(dp[i][k], dp[j][k - 1] + md);
				}
			}
		}
		return dp[n][d];
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->minDifficulty(vector<int>{6,5,4,3,2,1}, 2);
	delete solution;
	system("pause");
	return 0;
}