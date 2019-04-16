//Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) 
			return false;
		if (target < matrix[0][0] || target > matrix.back().back()) 
			return false;
		int row = matrix.size(), col = matrix[0].size();

		int left = 0, right = row - 1;
		while (left <= right)
		{
			int mid = (right + left) / 2;
			int min = matrix[mid][0], max = matrix[mid][col - 1];
			if (target < min)
			{
				right = mid - 1;
			}
			else if (target > max)
			{
				left = mid + 1;
			}
			else
			{
				int COL = mid;
				left = 0, right = col - 1;
				while (left <= right)
				{
					mid = (right + left) / 2;
					if (matrix[COL][mid] == target)
					{
						return true;
					}
					else if (matrix[COL][mid] > target)
					{
						right = mid - 1;
					}
					else
					{
						left = mid + 1;
					}
				}
				return false;
			}
		}

		return false;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<vector<int>> input = {
		{1,3}
	};
	auto result = solution->searchMatrix(input, 3);
	//cout << result << endlsearchMatrix
	delete(solution);
	system("pause");
	return 0;
}