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
		vector<int> res;
		int a = 0, b = 0, cnt1 = 0, cnt2 = 0, n = nums.size();
		for (int num : nums) 
		{
			if (num == a) 
				++cnt1;
			else if (num == b) 
				++cnt2;
			else if (cnt1 == 0) 
			{ 
				a = num; cnt1 = 1; 
			}
			else if (cnt2 == 0) 
			{ 
				b = num; cnt2 = 1; 
			}
			else 
			{ 
				--cnt1; 
				--cnt2; 
			}
		}
		cnt1 = cnt2 = 0;
		for (int num : nums) 
		{
			if (num == a) 
				++cnt1;
			else if (num == b) 
				++cnt2;
		}
		if (cnt1 > n / 3) 
			res.push_back(a);
		if (cnt2 > n / 3) 
			res.push_back(b);
		return res;
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