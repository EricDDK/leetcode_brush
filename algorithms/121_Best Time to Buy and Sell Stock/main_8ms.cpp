//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
//Note that you cannot sell a stock before you buy one.

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
		int buy = INT_MAX;
		for (int price : prices)
		{
			buy = min(buy, price);
			result = max(result, price - buy);
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
