//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 1, 2, 4, 5, 6, 7] might become[4, 5, 6, 7, 0, 1, 2]).
//
//You are given a target value to search.If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
//
//Your algorithm's runtime complexity must be in the order of O(log n).

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
	int search(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == target)
			{
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 4, 5, 6, 7, 0, 1, 2 };
	/*auto result = */solution->search(input, 0);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}