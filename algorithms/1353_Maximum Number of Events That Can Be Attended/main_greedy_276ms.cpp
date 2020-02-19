//Given an array of events where events[i] = [startDayi, endDayi].Every event i starts at startDayi and ends at endDayi.
//
//You can attend an event i at any day d where startTimei <= d <= endTimei.Notice that you can only attend one event at any time d.
//
//Return the maximum number of events you can attend.

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
	int maxEvents(vector<vector<int>>& events) {
		auto cmp = [](vector<int> &a, vector<int> &b) {return a.back() < b.back(); };
		sort(events.begin(), events.end(), cmp);
		int res = 0;
		vector<int> vec(100010, 0);
		for (const auto &v : events)
		{
			int s = v[0], e = v[1];
			int i = s;
			while (i <= e && vec[i] == 1) 
				i++;
			if (i <= e) 
			{
				vec[i] = 1;
				res++;
			}
		}
		return res;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->maxEvents(vector<vector<int>>{ {1, 2}, { 2,3 }, { 3,4 } });
	if (result != 3)
		throw;
	result = solution->maxEvents(vector<vector<int>>{ {1, 2}, { 2,3 }, { 3,4 }, { 1,2 } });
	if (result != 4)
		throw;
	result = solution->maxEvents(vector<vector<int>>{ {1, 4}, { 4,4 }, { 2,2 }, { 3,4 }, { 1,1 } });
	if (result != 4)
		throw;
	result = solution->maxEvents(vector<vector<int>>{ {1, 1}, { 1,2 }, { 1,3 }, { 1,4 }, { 1,5 }, { 1,6 }, { 1,7 } });
	if (result != 7)
		throw;
	result = solution->maxEvents(vector<vector<int>>{ {1, 2}, { 1,2 }, { 3,3 }, { 1,5 }, { 1,5 } });
	if (result != 5)
		throw;
	result = solution->maxEvents(vector<vector<int>>{ {1, 5}, { 1,5 }, { 1,5 }, { 2,3 }, { 2,3 } });
	if (result != 5)
		throw;
	delete solution;
	system("pause");
	return 0;
}