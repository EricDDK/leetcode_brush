//Given a triangle, find the minimum path sum from top to bottom.Each step you may move to adjacent numbers on the row below.

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
	int minimumTotal(vector<vector<int>>& triangle) {
		int result = INT_MIN;
		minimumTotalDFS(triangle, result, 0, 0, 0);
		return result;
	}

	void minimumTotalDFS(vector<vector<int>>& triangle, int& result, int total, int level, int index)
	{
		if (level >= triangle.size())
		{
			result = result != INT_MIN ? min(total, result) : total;
			return;
		}
		if (level + 1 <= triangle.size())
		{
			minimumTotalDFS(triangle, result, total + triangle[level][index], level + 1, index);
			minimumTotalDFS(triangle, result, total + triangle[level][index], level + 1, index + 1);
		}
	}

};

int main()
{
	Solution* solution = new Solution;
	vector<vector<int>> input = {
		{-1},
		{3,2},
		{1,-2,-1}
	};
	auto result = solution->minimumTotal(input);
	delete(solution);
	system("pause");
	return 0;
}