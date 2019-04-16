//Given a collection of integers that might contain duplicates, nums, return all possible subsets(the power set).
//
//Note: The solution set must not contain duplicate subsets.

#include <sstream>
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
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		if (nums.empty())
			return{};
		vector<vector<int>> result(1);
		sort(nums.begin(), nums.end());
		int size = 1;
		int last = nums[0];
		for (int i = 0; i < nums.size(); ++i)
		{
			if (last != nums[i]) {
				last = nums[i];
				size = result.size();
			}
			int newSize = result.size();
			for (int j = newSize - size; j < newSize; ++j)
			{
				result.push_back(result[j]);
				result.back().push_back(nums[i]);
			}
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 1,2,2 };
	auto result = solution->subsetsWithDup(input);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}