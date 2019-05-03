//Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
//A region is captured by flipping all 'O's into 'X's in that surrounded region.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
	void solve(vector<vector<char>>& board) {
		if (board.empty() || board[0].empty()) 
			return;
		int m = board.size(), n = board[0].size();
		for (int i = 0; i < m; ++i) 
		{
			for (int j = 0; j < n; ++j) 
			{
				if (i != 0 && i != m - 1 && j != 0 && j != n - 1) 
					continue;
				if (board[i][j] != 'O') 
					continue;
				board[i][j] = 'S';
				queue<int> q{ { i * n + j } };
				while (!q.empty()) 
				{
					int t = q.front(), x = t / n, y = t % n; q.pop();
					if (x >= 1 && board[x - 1][y] == 'O') { board[x - 1][y] = 'S'; q.push(t - n); }
					if (x < m - 1 && board[x + 1][y] == 'O') { board[x + 1][y] = 'S'; q.push(t + n); }
					if (y >= 1 && board[x][y - 1] == 'O') { board[x][y - 1] = 'S'; q.push(t - 1); }
					if (y < n - 1 && board[x][y + 1] == 'O') { board[x][y + 1] = 'S'; q.push(t + 1); }
				}
			}
		}
		for (int i = 0; i < m; ++i) 
		{
			for (int j = 0; j < n; ++j) 
			{
				if (board[i][j] == 'O') 
					board[i][j] = 'X';
				if (board[i][j] == 'S') 
					board[i][j] = 'O';
			}
		}
	}

};

int main()
{
	Solution* solution = new Solution;
	vector<vector<char>> input = {
		{ 'X','X','X','X' },
		{ 'X','O','O','X' },
		{ 'X','X','O','X' },
		{ 'X','O','X','X' }
	};
	/*auto result = */solution->solve(input);
	delete(solution);
	system("pause");
	return 0;
}