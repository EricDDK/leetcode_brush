//Given a non - empty array of integers, return the k most frequent elements.

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
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> uu;
		for (auto& n : nums)
		{
			if (uu.count(n))
			{
				uu[n]++;
			}
			else
			{
				uu[n] = 1;
			}
		}
		priority_queue<pair<int, int>> q;
		for (auto& u : uu)
		{
			q.push({u.second, u.first});
		}
		vector<int> result;
		for (int i = k - 1; i >= 0; --i)
		{
			result.push_back(q.top().second);
			q.pop();
		}
		return result;
	}
};

int main()
{
	Solution *solution = new Solution;
	auto result = solution->topKFrequent(vector<int>{1, 1, 1, 2, 2, 3}, 2);
	if (result.size() != 2)
		throw;
	result = solution->topKFrequent(vector<int>{1}, 1);
	if (result.size() != 1)
		throw;
	result = solution->topKFrequent(vector<int>{-1, -1}, 1);
	if (result.size() != 1)
		throw;
	result = solution->topKFrequent(vector<int>{1, 2}, 2);
	if (result.size() != 2)
		throw;
	delete solution;
	system("pause");
	return 0;
}