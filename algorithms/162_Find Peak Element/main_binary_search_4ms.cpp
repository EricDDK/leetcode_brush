//A peak element is an element that is greater than its neighbors.
//
//Given an input array nums, where nums[i] ¡Ù nums[i + 1], find a peak element and return its index.
//
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//You may imagine that nums[-1] = nums[n] = -¡Þ.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
	int findPeakElement(vector<int>& nums) {
		int start = 0, end = nums.size() - 1;
		int mid = 0;
		while (start < end)
		{
			mid = start + (end - start) / 2;
			if (nums[mid] <= nums[mid + 1])
			{
				start = mid + 1;
			}
			else
			{
				end = mid;
			}
		}
		return end;
	}
};

int main() {
	Solution* solution = new Solution;
	vector<int> input = { 1,2,3,1 };
	if (solution->findPeakElement(input) != 2)
		throw;
	input = { 1,2,1,3,5,6,4 };
	if (solution->findPeakElement(input) != 1 && solution->findPeakElement(input) != 5)
		throw;
	input = { 1 };
	if (solution->findPeakElement(input) != 0)
		throw;
	delete(solution);
	system("pause");
	return 0;
}