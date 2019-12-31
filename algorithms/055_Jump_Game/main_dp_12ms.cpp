//Given an array of non - negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.

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
	bool canJump(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
			if (dp[i] < 0)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->canJump(vector<int>{2,3,1,1,4});
	if (result != true)
		throw;
	delete solution;
	system("pause");
	return 0;
}