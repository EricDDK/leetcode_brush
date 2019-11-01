//You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
//
//Define a pair(u, v) which consists of one element from the first array and one element from the second array.
//
//Find the k pairs(u1, v1), (u2, v2) ...(uk, vk) with the smallest sums.

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
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		multimap<int, vector<int>> m;
		for (auto &n1 : nums1)
		{
			for (auto &n2 : nums2)
			{
				m.insert(make_pair(n1 + n2, vector<int>{n1, n2}));
			}
		}
		vector<vector<int>> result;
		auto it = m.begin();
		while (it != m.end() && k > 0)
		{
			result.push_back((*it).second);
			k--;
			it++;
		}
		return result;
	}
};

int main()
{
	Solution *solution = new Solution;
	auto result = solution->kSmallestPairs(vector<int>{1, 7, 11}, vector<int>{2, 4, 6}, 3);
	if (result.size() != 3)
		throw;
	result = solution->kSmallestPairs(vector<int>{1, 1, 2}, vector<int>{1, 2, 3}, 2);
	if (result.size() != 2)
		throw;
	result = solution->kSmallestPairs(vector<int>{1, 2}, vector<int>{3}, 3);
	if (result.size() != 2)
		throw;
	delete solution;
	system("pause");
	return 0;
}