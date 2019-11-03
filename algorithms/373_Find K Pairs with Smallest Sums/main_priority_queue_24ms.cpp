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

struct obj
{
	int a;
	int b;
};

struct cmp
{
	bool operator()(obj &a, obj &b)
	{
		return (a.a + a.b)< (b.a + b.b);
	}
};

class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<vector<int>> result;
		priority_queue<obj, vector<obj>, cmp> q;
		for (int i = 0; i < min((int)nums1.size(), k); ++i)
		{
			for (int j = 0; j < min((int)nums2.size(), k); ++j)
			{
				if (q.size() < k)
				{
					obj o;
					o.a = nums1[i];
					o.b = nums2[j];
					q.push(o);
				}
				else if (nums1[i] + nums2[j] < q.top().a + q.top().b)
				{
					obj o;
					o.a = nums1[i];
					o.b = nums2[j];
					q.push(o);
					q.pop();
				}
			}
		}
		while (!q.empty()) 
		{
			result.push_back(vector<int>{q.top().a, q.top().b});
			q.pop();
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