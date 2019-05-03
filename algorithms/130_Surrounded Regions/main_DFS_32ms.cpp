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
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1) && board[i][j] == 'O')
					solveDFS(board, i, j);
			}
		}
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				if (board[i][j] == 'S')
					board[i][j] = 'O';
			}
		}
	}

	void solveDFS(vector<vector<char>>& board, int row, int col) {
		if (board[row][col] == 'O')
		{
			board[row][col] = 'S';
			if (row > 0 && board[row - 1][col] == 'O')
				solveDFS(board, row - 1, col);
			if (row < board.size() - 1 && board[row + 1][col] == 'O')
				solveDFS(board, row + 1, col);
			// it must be col > 1. but > 0 is okay. col > 0 can't pass the unit test.
			if (col > 1 && board[row][col - 1] == 'O')
				solveDFS(board, row, col - 1);
			if (col < board[row].size() - 1 && board[row][col + 1] == 'O')
				solveDFS(board, row, col + 1);
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