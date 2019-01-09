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
		unordered_map<int, int> map;
		for (int i : nums)
		{
			map[i] = 0;
		}
		int i = 0;
		for (i = 0; i < nums.size(); ++i)
		{
			if (!map.count(i))
			{
				return i;
			}
		}
		return i;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 0 };
	auto result = solution->missingNumber(input);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}