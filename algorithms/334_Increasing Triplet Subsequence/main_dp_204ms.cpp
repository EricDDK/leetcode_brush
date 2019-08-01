//Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
//Formally the function should :
//
//Return true if there exists i, j, k
//such that arr[i] < arr[j] < arr[k] given 0 ¡Ü i < j < k ¡Ü n - 1 else return false.
//	Note : Your algorithm should run in O(n) time complexity and O(1) space complexity.

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
	bool increasingTriplet(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[j] < nums[i])
				{
					dp[i] = max(dp[i], dp[j] + 1);
					if (dp[i] >= 3)
						return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	Solution *solution = new Solution;
	vector<int> input;
	input = { 5,1,5,5,2,5,4 };
	if (!solution->increasingTriplet(input))
		throw;
	input = { 1 };
	if (solution->increasingTriplet(input))
		throw;
	input = { 1,2,3,4,5 };
	if (!solution->increasingTriplet(input))
		throw;
	input = {5,4,3,2,1};
	if (solution->increasingTriplet(input))
		throw;
	delete solution;
	system("pause");
	return 0;
}