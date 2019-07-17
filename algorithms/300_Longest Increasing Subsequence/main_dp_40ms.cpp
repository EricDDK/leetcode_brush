//Given an unsorted array of integers, find the length of longest increasing subsequence.

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
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);
		int result = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] > nums[j])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			result = max(result, dp[i]);
		}
		return result;
	}
};

int main()
{
	Solution *solution = new Solution;
	vector<int> input = { 10,9,2,5,3,7,101,18 };
	if (solution->lengthOfLIS(input) != 4)
		throw;
	
	delete solution;
	system("pause");
	return 0;
}