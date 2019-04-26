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
		for (int i = 1; i < triangle.size(); ++i)
		{
			for (int j = 0; j < triangle[i].size(); ++j)
			{
				if (j == 0)
					triangle[i][j] += triangle[i - 1][j];
				else if (j == triangle[i].size() - 1)
					triangle[i][j] += triangle[i - 1][j - 1];
				else
					triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
			}
		}
		return *min_element(triangle.back().begin(), triangle.back().end());
	}

};

int main()
{
	Solution* solution = new Solution;
	vector<vector<int>> input = {
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3}
	};
	auto result = solution->minimumTotal(input);
	delete(solution);
	system("pause");
	return 0;
}