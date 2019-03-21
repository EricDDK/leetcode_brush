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
		int left = 0, right = nums.size() - 1, mid;
		while (left <= right)
		{
			mid = (left + right) >> 1;
			if (nums[mid] == target) 
				return true;
			if (nums[left] == nums[mid] && nums[mid] == nums[right])
			{
				++left;
				--right;
			}
			else if (nums[left] <= nums[mid])
			{
				if ((nums[left] <= target) && (nums[mid] > target)) 
					right = mid - 1;
				else 
					left = mid + 1;
			}
			else
			{
				if ((nums[mid] < target) && (nums[right] >= target)) 
					left = mid + 1;
				else 
					right = mid - 1;
			}
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