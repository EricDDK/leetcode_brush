//Given a sorted integer array without duplicates, return the summary of its ranges.

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
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result;
		if (nums.size() <= 1)
			return nums.empty() ? result : (vector<string>(1, to_string(nums[0])));
		int start = 0, end = 0;
		auto func = [&]()
		{
			if (end > start)
			{
				string s = to_string(nums[start]) + "->" + to_string(nums[end]);
				result.push_back(s);
			}
			else
			{
				result.push_back(to_string(nums[start]));
			}
		};
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] == nums[i - 1] + 1)
			{
				end = i;
			}
			else
			{
				func();
				start = i;
				end = i;
			}
			if (end == nums.size() - 1)
			{
				func();
			}
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 0,1,2,4,5,7 };
	auto result = solution->summaryRanges(input);
	if (result.size() != 3 || result[2] != "7")
		throw;
	input = { 0,2,3,4,6,8,9 };
	result = solution->summaryRanges(input);
	if (result.size() != 4 || result[3] != "8->9")
		throw;
	input = { -1 };
	result = solution->summaryRanges(input);
	if (result.size() != 1 || result[0] != "-1")
		throw;
	delete solution;
	system("pause");
	return 0;
}