//Given a set of distinct integers, nums, return all possible subsets(the power set).
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
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result(1);
		//sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i)
		{
			int size = result.size();
			for (int j = 0; j < size; ++j)
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
	vector<int> input = {1,2,3};
	auto result = solution->subsets(input);
	//cout << result << endlsearchMatrix
	delete(solution);
	system("pause");
	return 0;
}