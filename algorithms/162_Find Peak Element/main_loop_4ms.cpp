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
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i - 1] > nums[i])
			{
				return i - 1;
			}
		}
		return nums.size() - 1;
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
	input = { 1, 2 };
	if (solution->findPeakElement(input) != 1)
		throw;
	input = { 1 };
	if (solution->findPeakElement(input) != 0)
		throw;
	delete(solution);
	system("pause");
	return 0;
}