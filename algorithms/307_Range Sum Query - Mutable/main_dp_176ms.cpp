//Given an integer array nums, find the sum of the elements between indices i and j(i ¡Ü j), inclusive.
//
//The update(i, val) function modifies nums by updating the element at index i to val.

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

class NumArray {
public:
	NumArray(vector<int>& nums) {
		if (nums.empty())
			return;
		dp.resize(nums.size());
		dp[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			dp[i] = dp[i - 1] + nums[i];
		}
	}

	void update(int i, int val) {
		int diff; int old;
		if (i == 0) {
			diff = val - dp[0];
		}
		else {
			old = dp[i] - dp[i - 1];
			diff = val - old;
		}
		for (int x = i; x <dp.size(); x++) {
			dp[x] = dp[x] + diff;
		}
	}

	int sumRange(int i, int j) {
		int result = dp[j];
		if (i >0)
			result = dp[j] - dp[i - 1];
		return result;
	}
private:
	vector<int> dp;
};

int main()
{
	vector<int> input = {1,3,5};
	NumArray na(input);
	if (na.sumRange(0, 2) != 9)
		throw;
	na.update(1, 2);
	if (na.sumRange(0, 2) != 8)
		throw;

	input = {-1};
	na = NumArray(input);
	if (na.sumRange(0, 0) != -1)
		throw;
	na.update(0, 1);
	if (na.sumRange(0, 0) != 1)
		throw;
	system("pause");
	return 0;
}