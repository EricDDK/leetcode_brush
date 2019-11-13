//A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative.
//The first difference(if one exists) may be either positive or negative.A sequence with fewer than two elements is trivially a wiggle sequence.
//
//For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences(6, -3, 5, -7, 3) are alternately positive and negative
//.In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.
//
//Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence.
//A subsequence is obtained by deleting some number of elements(eventually, also zero) from the original sequence, 
//leaving the remaining elements in their original order.

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
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() <= 1) 
			return nums.size();
		vector<int> p(nums.size(), 1);
		vector<int> q(nums.size(), 1);
		for (int i = 1; i < nums.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] > nums[j])
				{
					p[i] = max(p[i], q[j] + 1);
				}
				else if (nums[i] < nums[j])
				{
					q[i] = max(q[i], p[j] + 1);
				}
			}
		}
		return max(p.back(), q.back());
	}

};

int main()
{
	Solution *solution = new Solution;
	auto result = solution->wiggleMaxLength(vector<int>{1, 7, 4, 9, 2, 5});
	if (result != 6)
		throw;
	result = solution->wiggleMaxLength(vector<int>{1, 17, 5, 10, 13, 15, 10, 5, 16, 8});
	if (result != 7)
		throw;
	result = solution->wiggleMaxLength(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9});
	if (result != 2)
		throw;
	delete solution;
	system("pause");
	return 0;
}