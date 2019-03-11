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
		vector<vector<int>> result;
		vector<int> tmp;
		subsetsDFS(nums, result, tmp, 0);
		return result;
	}

	void subsetsDFS(vector<int>& nums, vector<vector<int>>& result, vector<int>& tmp, int index) {
		result.push_back(tmp);
		for (int i = index; i < nums.size(); ++i)
		{
			tmp.push_back(nums[i]);
			subsetsDFS(nums, result, tmp, i + 1);
			tmp.pop_back();
		}
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