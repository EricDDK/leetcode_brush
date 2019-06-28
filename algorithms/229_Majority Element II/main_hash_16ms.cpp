//Given an integer array of size n, find all elements that appear more than n / 3 times.
//
//Note: The algorithm should run in linear time and in O(1) space.

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
	vector<int> majorityElement(vector<int>& nums) {
		int ratio = nums.size() / 3;
		unordered_map<int, int> u;
		vector<int> result;
		for (auto& n : nums)
		{
			if (u.count(n))
			{
				u[n]++;
			}
			else
				u[n] = 1;
		}
		for (auto& i : u)
		{
			if (i.second > ratio)
				result.push_back(i.first);
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 3,2,3 };
	auto result = solution->majorityElement(input);
	if (result.size() != 1)
		throw;
	input = { 1,1,1,3,3,2,2,2 };
	result = solution->majorityElement(input);
	if (result.size() != 2)
		throw;
	delete solution;
	system("pause");
	return 0;
}