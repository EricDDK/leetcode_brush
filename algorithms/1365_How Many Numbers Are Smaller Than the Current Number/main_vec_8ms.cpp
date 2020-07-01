//Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it.That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
//
//Return the answer in an array.

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
#include <numeric>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		int count = nums.size();
		if (count == 0)
			return vector<int>();
		vector<int> result(count, 0);
		vector<int> vec(101, 0);
		for (int i = 0; i < count; ++i)
		{
			vec[nums[i]]++;
		}
		for (int i = 1; i < 101; ++i)
		{
			vec[i] += vec[i - 1];
		}
		for (int i = 0; i < count; ++i)
		{
			if (nums[i] == 0)
				result[i] = 0;
			else
				result[i] = vec[nums[i] - 1];
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 8,1,2,2,3 };
	auto result = solution->smallerNumbersThanCurrent(input);
	if (result != vector<int>{4, 0, 1, 1, 3})
		throw;
	input = { 6,5,4,8 };
	result = solution->smallerNumbersThanCurrent(input);
	if (result != vector<int>{2, 1, 0, 3})
		throw;
	input = { 7,7,7,7 };
	result = solution->smallerNumbersThanCurrent(input);
	if (result != vector<int>{0, 0, 0, 0})
		throw;
	delete solution;
	system("pause");
	return 0;
}