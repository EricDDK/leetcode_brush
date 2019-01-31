// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

#include<sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		sort(candidates.begin(), candidates.end());
        combinationSumDFS(candidates, target, 0, {}, result);
		return result;
    }

	void combinationSumDFS(vector<int> &candidates, int target, int start, vector<int> out, vector<vector<int>> &res)
	{
		if (target < 0)
			return;
		if (target == 0)
		{
			res.push_back(out);
			return;
		}
		for (int i = start; i < candidates.size(); ++i)
		{
			if (i > start && candidates[i] == candidates[i - 1]) 
				continue;
			out.push_back(candidates[i]);
			combinationSumDFS(candidates, target - candidates[i], i + 1, out, res);
			out.pop_back();
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = {2,3,6,7};
	auto result = solution->combinationSum2(input, 7);
	delete solution;
	//cout << result << endl;
	return 0;
}
