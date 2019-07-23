//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete as many transactions as you like(ie, buy one and sell one share of the stock multiple times) with the following restrictions :
//
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
//After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

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
	int maxProfit(vector<int>& prices) {
		int buy = INT_MIN, preBuy = 0, sell = 0, preSell = 0;
		for (int i = 0; i < prices.size(); ++i)
		{
			preBuy = buy;
			buy = max(preSell - prices[i], preBuy);
			preSell = sell;
			sell = max(preBuy + prices[i], preSell);
		}
		return sell;
	}
};

int main()
{
	Solution *solution = new Solution;
	vector<int> input = { 1,2,3,0,2 };
	if (solution->maxProfit(input) != 3)
		throw;
	delete solution;
	system("pause");
	return 0;
}