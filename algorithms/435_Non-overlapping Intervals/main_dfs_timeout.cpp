//Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non - overlapping.

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
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int result = INT_MAX;
		dfs(intervals, vector<vector<int>>(), 0, 0, result);
		return result;
	}

	void dfs(const vector<vector<int>>& intervals, vector<vector<int>> tv, int index, int out, int& result) {
		if (index == intervals.size())
		{
			result = min(result, out);
			return;
		}
		bool over = false;
		for (int i = 0; i < tv.size(); ++i)
		{
			if (
				(intervals[index][0] <= tv[i][0] && intervals[index][1] > tv[i][0]) ||
				(intervals[index][0] < tv[i][1] && intervals[index][1] >= tv[i][1])
				)
			{
				over = true;
				break;
			}
		}
		if (over)
		{
			dfs(intervals, tv, index + 1, out + 1, result);
		}
		else
		{
			dfs(intervals, tv, index + 1, out + 1, result);
			tv.push_back(intervals[index]);
			dfs(intervals, tv, index + 1, out, result);
			tv.pop_back();
		}
	}

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->eraseOverlapIntervals(vector<vector<int>>{
		{1, 2}, { 2,3 }, { 3,4 }, { 1,3 },
	});
	if (result != 1)
		throw;
	result = solution->eraseOverlapIntervals(vector<vector<int>>{
		{1, 2}, { 1,2 }, { 1,2 }
	});
	if (result != 2)
		throw;
	result = solution->eraseOverlapIntervals(vector<vector<int>>{
		{1, 2}, { 2,3 }
	});
	if (result != 0)
		throw;
	delete solution;
	system("pause");
	return 0;
}