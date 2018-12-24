//Given an array, rotate the array to the right by k steps, where k is non - negative.

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
	int rob(vector<int>& nums) {
		vector<int> value;
		int max = 0;
		for (auto i = 0; i < nums.size(); ++i)
		{
			int value_i_2 = (i - 2) >= 0 ? value[i - 2] : 0;
			int value_i_1 = (i - 1) >= 0 ? value[i - 1] : 0;
			value.push_back(max(nums[i] + value_i_2, value_i_1));
			max = (max >= value[i]) ? max : value[i];
		}
		return max;
	}
};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	vector<int> input = { 1, 2, 3, 4 };
	auto result = solution->rob(input);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
