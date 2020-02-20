//You are given a list of non - negative integers, a1, a2, ..., an, and a target, S.Now you have 2 symbols + and -.For each integer, you should choose one from + and -as its new symbol.
//
//Find out how many ways to assign symbols to make sum of integers equal to target S.

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
	int findTargetSumWays(vector<int>& nums, int S) {
		int result = 0;
		dfs(nums, S, 0, 0 + nums[0], result);
		dfs(nums, S, 0, 0 - nums[0], result);
		return result;
	}

	void dfs(vector<int>& nums, int S, int i, int out, int& result) {
		if (i == nums.size() - 1)
		{
			if (out == S)
				result++;
			return;
		}
		dfs(nums, S, i + 1, out + nums[i + 1], result);
		dfs(nums, S, i + 1, out - nums[i + 1], result);
	}

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->findTargetSumWays(vector<int>{ 1, 1, 1, 1, 1 }, 3);
	if (result != 5)
		throw;
	result = solution->findTargetSumWays(vector<int>{ 1, 0 }, 1);
	if (result != 2)
		throw;
	delete solution;
	system("pause");
	return 0;
}