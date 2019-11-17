//Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

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

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		set<vector<int>> s;
		combinationSum4DFS(s, nums, target, vector<int>{}, 0);
		return s.size();
	}

	void combinationSum4DFS(set<vector<int>> &s, vector<int>& nums, int tartget, vector<int> out, int total) {
		if (total == tartget)
		{
			s.insert(out);
			return;
		}
		if (total > tartget)
			return;
		for (int i = 0; i < nums.size(); ++i)
		{
			out.push_back(nums[i]);
			combinationSum4DFS(s, nums, tartget, out, total + nums[i]);
			out.pop_back();
		}
	}

};

int main()
{
	Solution *solution = new Solution;
	auto result = solution->combinationSum4(vector<int>{1, 2, 3}, 4);
	if (result != 7)
		throw;
	result = solution->combinationSum4(vector<int>{4,2,1}, 32);
	if (result != 7)
		throw;
	delete solution;
	system("pause");
	return 0;
}