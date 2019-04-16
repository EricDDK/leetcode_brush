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
		vector<vector<int>> result;
		vector<int> out = {};
		sort(nums.begin(), nums.end());
		subsetsWithDupDFS(nums, result, out, 0);
		return result;
	}

	void subsetsWithDupDFS(vector<int>& nums, vector<vector<int>> &result, vector<int> &out, int index)
	{
		result.push_back(out);
		for (int i = index; i < nums.size(); ++i)
		{
			out.push_back(nums[i]);
			subsetsWithDupDFS(nums, result, out, i + 1);
			out.pop_back();
			while (i + 1 < nums.size() && nums[i] == nums[i + 1])
				++i;
		}
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