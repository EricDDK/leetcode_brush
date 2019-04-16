//Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return[-1, -1].

#include<sstream>
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
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1, mid = 0;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (nums[mid] == target)
			{
				return doubleDispose(nums, left, right, mid, target);
			}
			else if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return{ -1, -1 };
	}

	vector<int> doubleDispose(vector<int>& nums, int nLeft, int nRight, int nMid, int target)
	{
		nLeft = nMid;
		nRight = nMid;
		while (nLeft > 0 && nums[nLeft - 1] == target)
		{
			nLeft--;
		}
		while (nRight < nums.size() - 1 && nums[nRight + 1] == target)
		{
			nRight++;
		}
		return{ nLeft, nRight };
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 2, 2 };
	auto result = solution->searchRange(input, 2);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}