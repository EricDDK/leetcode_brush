//Given a sorted array nums, remove the duplicates in - place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this by modifying the input array in - place with O(1) extra memory.

#include "iostream"
#include <vector>
#include <unordered_map>
#include <hash_set>
#include "windows.h"
#include "algorithm"
#include <stack>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int result = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i == 0)
			{
				result++;
			}
			else if (nums[i] > nums[i - 1])
			{
				nums[result] = nums[i];
				result++;
			}
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	auto result = solution->removeDuplicates(input);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
