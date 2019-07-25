//You are given coins of different denominations and a total amount of money amount.Write a function to compute the fewest number of coins that you need to make up that amount.
//If that amount of money cannot be made up by any combination of the coins, return -1.

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
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		int i, j;
		for (i = 1; i <= amount; ++i)
		{
			for (j = 0; j < coins.size(); ++j)
			{
				if (coins[j] <= i)
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
		return (dp[amount] > amount) ? -1 : dp[amount];
	}
};

int main()
{
	Solution *solution = new Solution;
	vector<int> input;
	//
	input = { 1, 2, 5 };
	if (solution->coinChange(input, 11) != 3)
		throw;
	input = { 2 };
	if (solution->coinChange(input, 3) != -1)
		throw;
	//
	delete solution;
	system("pause");
	return 0;
}