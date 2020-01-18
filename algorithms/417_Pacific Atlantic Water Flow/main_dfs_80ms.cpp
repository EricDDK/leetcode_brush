//Given an m x n matrix of non - negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
//
//Water can only flow in four directions(up, down, left, or right) from a cell to another one with height equal or lower.
//
//Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

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
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<vector<int>> result;
		if (matrix.empty() || matrix[0].empty()) 
			return result;
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<bool>> pacific(m, vector<bool>(n, false));
		vector<vector<bool>> atlantic(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i)
		{
			dfs(pacific, i, 0, matrix);
			dfs(atlantic, i, n - 1, matrix);
		}
		for (int i = 0; i < n; ++i)
		{
			dfs(pacific, 0, i, matrix);
			dfs(atlantic, m - 1, i, matrix);
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (pacific[i][j] && atlantic[i][j])
				{
					result.push_back({i, j});
				}
			}
		}
		return result;
	}

	void dfs(vector<vector<bool>>& visited, int i, int j, vector<vector<int>>& matrix, int pre = INT_MIN) {
		int m = matrix.size(), n = matrix[0].size();
		if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || matrix[i][j] < pre)
			return;
		visited[i][j] = true;
		dfs(visited, i + 1, j, matrix, matrix[i][j]);
		dfs(visited, i - 1, j, matrix, matrix[i][j]);
		dfs(visited, i, j + 1, matrix, matrix[i][j]);
		dfs(visited, i, j - 1, matrix, matrix[i][j]);
	}

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->pacificAtlantic(vector<vector<int>>{
		{1,2,2,3,5},
		{3,2,3,4,4},
		{2,4,5,3,1},
		{6,7,1,4,5},
		{5,1,1,2,4}
	});
	if (result.size() != 7)
		throw;
	delete solution;
	system("pause");
	return 0;
}