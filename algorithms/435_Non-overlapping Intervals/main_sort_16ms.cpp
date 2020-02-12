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
		int result = 0;
		int n = intervals.size();
		int last = 0;
		sort(intervals.begin(), intervals.end());
		for (int i = 1; i < n; ++i)
		{
			if (intervals[i][0] < intervals[last][1])
			{
				++result;
				if (intervals[i][1] < intervals[last][1]) 
					last = i;
			}
			else
			{
				last = i;
			}
		}
		return result;
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