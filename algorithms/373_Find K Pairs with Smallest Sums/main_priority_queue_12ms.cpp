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

struct HeapItem {
	int v1 = 0, v2 = 0;//val
	int p1 = 0, p2 = 0;//index
};

typedef struct HeapItem obj;
class compare {
public:
	bool operator()(obj a, obj b) {
		return a.v1 + a.v2>b.v1 + b.v2;//min heap
	}
};

class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		priority_queue<obj, vector<obj>, compare>pq;
		vector<vector<int>>res;
		if (nums1.size() <= 0) {

			return res;
		}
		if (nums2.size() <= 0) {

			return res;
		}
		for (int i = 0; i<min((int)nums1.size(), k); i++) {
			obj o1;
			o1.v1 = nums1[i];
			o1.v2 = nums2[0];
			pq.push(o1);
		}

		while (res.size()<min((int)nums1.size()*(int)nums2.size(), k)) {
			obj temp = pq.top();
			pq.pop();
			res.push_back({ temp.v1,temp.v2 });
			if (temp.p2 + 1 >= nums2.size())
				continue;
			temp.v2 = nums2[temp.p2 + 1];
			temp.p2 += 1;
			pq.push(temp);
		}
		return res;
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