//We are playing the Guess Game.The game is as follows :
//
//I pick a number from 1 to n.You have to guess which number I picked.
//
//Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
//
//However, when you guess a particular number x, and you guess wrong, you pay $x.You win the game when you guess the number I picked.

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
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		return cost(dp, 1, n);
	}

	int cost(vector<vector<int>>& dp, int start, int end) {
		int result = INT_MAX;
		if (start >= end)
			return 0;
		if (dp[start][end] != 0)
			return dp[start][end];
		for (int i = start; i <= end; ++i)
		{
			int tmp = i + max(cost(dp, start, i - 1), cost(dp, i + 1, end));
			if (tmp < result)
				result = tmp;
		}
		dp[start][end] = result;
		return result;
	}

};

int main()
{
	Solution *solution = new Solution;
	auto result = solution->getMoneyAmount(10);
	if (result != 16)
		throw;
	delete solution;
	system("pause");
	return 0;
}