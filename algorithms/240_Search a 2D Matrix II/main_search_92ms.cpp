//Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
//
//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.

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
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;
		if (target < matrix[0][0] || target > matrix.back().back()) 
			return false;
		int x = matrix.size() - 1, y = 0;
		while (true)
		{
			if (target == matrix[x][y])
				return true;
			else if (matrix[x][y] < target)
				++y;
			else
				--x;
			if (x < 0 || y >= matrix[0].size())
				return false;
		}
		return false;
	}

};

int main()
{
	Solution* solution = new Solution;
	vector<vector<int>> input = {
		{1,   4,  7, 11, 15},
		{2,   5,  8, 12, 19},
		{3,   6,  9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};
	if (!solution->searchMatrix(input, 5))
		throw;
	if (solution->searchMatrix(input, 20))
		throw;
	delete solution;
	system("pause");
	return 0;
}