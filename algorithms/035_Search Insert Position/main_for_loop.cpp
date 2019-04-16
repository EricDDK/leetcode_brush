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
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			if (nums[i] >= target)
			{
				return i;
			}
		}
		return size;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 1, 3, 5, 6 };
	auto result = solution->searchInsert(input,2);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
