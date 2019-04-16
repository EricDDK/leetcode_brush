//Given a sorted array and a target value, return the index if the target is found.If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.

#include "iostream"
#include <vector>
#include <unordered_map>
#include <map>
#include <hash_set>
#include "windows.h"
#include "algorithm"
#include <stack>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.back() < target)
		{
			return nums.size();
		}
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] = target)
			{
				return mid;
			}
			else if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		return right;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 1, 3, 5, 6 };
	auto result = solution->searchInsert(input,5);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
