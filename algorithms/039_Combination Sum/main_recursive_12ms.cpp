// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of times.

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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
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
			out.push_back(candidates[i]);
			combinationSumDFS(candidates, target - candidates[i], i, out, res);
			out.pop_back();
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = {2,3,6,7};
	auto result = solution->combinationSum(input, 7);
	delete solution;
	//cout << result << endl;
	return 0;
}
