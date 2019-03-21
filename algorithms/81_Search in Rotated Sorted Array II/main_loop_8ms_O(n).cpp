//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 0, 1, 2, 2, 5, 6] might become[2, 5, 6, 0, 0, 1, 2]).
//
//You are given a target value to search.If found in the array return true, otherwise return false.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.empty())
			return false;
		if (nums[0] == target || nums[nums.size() - 1] == target) 
			return true;
		int first = nums[0];
		if (first < target)
		{
			for (int i = nums.size() - 1; i >= 0; --i)
			{
				if (nums[i] == target)
					return true;
				
			}
		}
		else if (first > target)
		{
			for (int i = 0; i < nums.size(); ++i)
			{
				if (nums[i] == target)
					return true;
				
			}
		}
		else
		{
			return true;
		}
		return false;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 1,2,1 };
	auto result = solution->search(input, 2);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}