//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

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
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (nums.empty())
			return false;
		int start = 0, end = 0;
		for (start = 0; start < nums.size() - 1; ++start)
		{
			for (end = start + 1; end <= start + k && end < nums.size(); ++end)
			{
				if (abs((long long)nums[end] - (long long)nums[start]) <= t)
					return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 1,2,3,1 };
	if (!solution->containsNearbyAlmostDuplicate(input, 3, 0))
		throw;
	input = { 1,0,1,1 };
	if(!solution->containsNearbyAlmostDuplicate(input, 1, 2))
		throw;
	input = { 1,5,9,1,5,9 };
	if (solution->containsNearbyAlmostDuplicate(input, 2, 3))
		throw;
	input = {};
	if (solution->containsNearbyAlmostDuplicate(input, 0, 0))
		throw;
	delete solution;
	system("pause");
	return 0;
}