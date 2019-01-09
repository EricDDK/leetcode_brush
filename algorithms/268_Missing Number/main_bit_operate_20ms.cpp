//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

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
	int missingNumber(vector<int>& nums) {
		int result = nums.size();
		int i = 0;
		for (int num : nums)
		{
			result ^= num;
			result ^= i;
			++i;
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
	auto result = solution->missingNumber(input);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}