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

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int left = matrix[0][0], right = matrix.back().back();
		while (left < right) {
			int mid = left + (right - left) / 2;
			int cnt = search_less_equal(matrix, mid);
			if (cnt < k) left = mid + 1;
			else right = mid;
		}
		return left;
	}
	int search_less_equal(vector<vector<int>>& matrix, int target) {
		int n = matrix.size(), i = n - 1, j = 0, res = 0;
		while (i >= 0 && j < n) {
			if (matrix[i][j] <= target) {
				res += i + 1;
				++j;
			}
			else {
				--i;
			}
		}
		return res;
	}
};

int main()
{
	Solution *solution = new Solution;
	auto result = solution->kthSmallest(vector<vector<int>>{vector<int>{1, 5, 9}, vector<int>{10, 11, 13}, vector<int>{12, 13, 15}}, 8);
	if (result != 13)
		throw;
	result = solution->kthSmallest(
		vector<vector<int>>{
			vector<int>{1, 4, 7, 11, 15},
			vector<int>{2, 5, 8, 12, 19},
			vector<int>{3, 6, 9, 16, 22},
			vector<int>{18, 21, 23, 26, 30}
	}, 5);
	if (result != 5)
		throw;
	delete solution;
	system("pause");
	return 0;
}