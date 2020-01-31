//Given an 2D board, count how many battleships are in it.The battleships are represented with 'X's, empty slots are represented with '.'s.You may assume the following rules :
//You receive a valid board, made of only battleships or empty slots.
//Battleships can only be placed horizontally or vertically.In other words, they can only be made of the shape 1xN(1 row, N columns) or Nx1(N rows, 1 column), where N can be of any size.
//At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

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
	int countBattleships(vector<vector<char>>& board) {
		if (board.empty() || board[0].empty()) 
			return 0;
		int result = 0;
		m = board.size();
		n = board[0].size();
		vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == 'X' && !visited[i][j])
				{
					int v = 0, h = 0;
					dfs(board, visited, i, j, v, h);
					if (v == i || h == j)
						result++;
				}
			}
		}
		return result;
	}

	void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, int& v, int& h) {
		if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] == '.')
			return;
		v |= i;
		h |= j;
		visited[i][j] = true;
		dfs(board, visited, i - 1, j, v, h);
		dfs(board, visited, i + 1, j, v, h);
		dfs(board, visited, i, j - 1, v, h);
		dfs(board, visited, i, j + 1, v, h);
	}

	int m, n;

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->countBattleships(vector<vector<char>>{
		{'X','.','.','X'},
		{'.','.','.','X'},
		{'.','.','.','X'},
	});
	if (result != 2)
		throw;
	delete solution;
	system("pause");
	return 0;
}