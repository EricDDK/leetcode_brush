//Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.
//
//For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store - 1 for the interval i.Finally, you need output the stored value of each interval as an array.
//
//Note:
//
//You may assume the interval's end point is always bigger than its start point.
//You may assume none of these intervals have the same start point.

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

class Node
{
public:
	int index;
	int min;
	void push(int v)
	{

	}
};

class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		vector<int> result;
		vector<int> starts;
		unordered_map<int, int> m;
		for (int i = 0; i < intervals.size(); ++i)
		{
			m[intervals[i][0]] = i;
			starts.push_back(intervals[i][0]);
		}
		sort(starts.rbegin(), starts.rend());
		for (auto interval : intervals)
		{
			int i = 0;
			for (; i < starts.size(); ++i)
			{
				if (starts[i] < interval[1])
					break;
			}
			result.push_back((i > 0) ? m[starts[i - 1]] : -1);
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->findRightInterval(vector<vector<int>>{
		{1, 2}
	});
	if (result != vector<int>{-1})
		throw;
	result = solution->findRightInterval(vector<vector<int>>{
		{3,4}, { 2,3 }, { 1,2 }
	});
	if (result != vector<int>{-1, 0, 1})
		throw;
	result = solution->findRightInterval(vector<vector<int>>{
		{1, 4}, { 2,3 }, { 3,4 }
	});
	if (result != vector<int>{-1, 2, -1})
		throw;
	delete solution;
	system("pause");
	return 0;
}