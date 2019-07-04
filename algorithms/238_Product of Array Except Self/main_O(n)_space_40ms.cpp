//Given an array nums of n integers where n > 1, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

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
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> begin(nums.size(), 1);
		vector<int> end(nums.size(), 1);
		vector<int> result(nums.size());
		int i;
		for (i = 1; i < nums.size(); ++i)
		{
			begin[i] = begin[i - 1] * nums[i - 1];
		}
		for (i = nums.size() - 2; i >= 0; --i)
		{
			end[i] = end[i + 1] * nums[i + 1];
		}
		for (i = 0; i < nums.size(); ++i)
		{
			result[i] = begin[i] * end[i];
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = {1,2,3,4};
	auto result = solution->productExceptSelf(input);
	if (result[0] != 24 || result[1] != 12 || result[2] != 8 || result[3] != 6)
		throw;
	delete solution;
	system("pause");
	return 0;
}