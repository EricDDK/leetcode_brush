//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete as many transactions as you like(i.e., buy one and sell one share of the stock multiple times).
//
//Note: You may not engage in multiple transactions at the same time(i.e., you must sell the stock before you buy again).

#include "iostream"
#include <vector>
#include <unordered_map>
#include <map>
#include <hash_set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0;
		if (prices.empty())
		{
			return result;
		}
		for (int i = 0; i < prices.size()-1; ++i)
		{
			if (prices[i] < prices[i+1])
			{
				result += (prices[i + 1] - prices[i]);
			}
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 7, 1, 5, 3, 6, 4 };
	auto result = solution->maxProfit(input);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
