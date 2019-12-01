//Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
//
//Note that it is the kth smallest element in the sorted order, not the kth distinct element.

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

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int, vector<int>, cmp> q;
		for (auto &ma : matrix)
		{
			for (auto &m : ma)
			{
				q.push(m);
			}
		}
		for (int i = 0; i < k - 1; ++i)
		{
			q.pop();
		}
		return q.top();
	}
};

int main()
{
	Solution *solution = new Solution;
	auto result = solution->kthSmallest(vector<vector<int>>{vector<int>{1, 5, 9}, vector<int>{10, 11, 13}, vector<int>{12, 13, 15}}, 8);
	if (result != 13)
		throw;
	delete solution;
	system("pause");
	return 0;
}