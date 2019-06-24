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
		set<long long> s;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i > k)
				s.erase(nums[i - k - 1]);
			auto iter = s.lower_bound((long long)nums[i] - t);
			if (iter != s.end() && (*iter) - nums[i] <= t)
				return true;
			s.insert(nums[i]);
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