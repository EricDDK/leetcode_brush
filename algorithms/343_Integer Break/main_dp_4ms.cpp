//Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers.\
//Return the maximum product you can get.

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
	int integerBreak(int n) {
		vector<int> dp(n + 1, 1);
		int i, j;
		for (i = 3; i < n + 1; ++i)
		{
			for (j = 1; j < i; ++j)
			{
				dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
			}
		}
		return dp.back();
	}

};

int main()
{
	Solution *solution = new Solution;
	if (solution->integerBreak(3) != 2)
		throw;
	if (solution->integerBreak(2) != 1)
		throw;
	if (solution->integerBreak(10) != 36)
		throw;
	delete solution;
	system("pause");
	return 0;
}