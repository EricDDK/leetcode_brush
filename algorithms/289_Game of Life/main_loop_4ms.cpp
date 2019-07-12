//According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
//
//Given a board with m by n cells, each cell has an initial state live(1) or dead(0).Each cell interacts with its eight neighbors(horizontal, vertical, diagonal) using the following four rules(taken from the above Wikipedia article) :
//
//	Any live cell with fewer than two live neighbors dies, as if caused by under - population.
//	Any live cell with two or three live neighbors lives on to the next generation.
//	Any live cell with more than three live neighbors dies, as if by over - population..
//	Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//	Write a function to compute the next state(after one update) of the board given its current state.The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.
//
//	Example:

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
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty() || board[0].empty())
			return;
		int row = board.size();
		int col = board[0].size();
		vector<vector<int>> result(row, vector<int>(col, 0));
		int i, j, count;
		for (i = 0; i < row; ++i)
		{
			for (j = 0; j < col; ++j)
			{
				count = 0;
				if (i >= 1 && j >= 1 && board[i - 1][j - 1] == 1)
					count++;
				if (i >= 1 && board[i - 1][j] == 1)
					count++;
				if (i >= 1 && j < col - 1 && board[i - 1][j + 1] == 1)
					count++;
				if (j >= 1 && board[i][j - 1] == 1)
					count++;
				if (j < col - 1 && board[i][j + 1] == 1)
					count++;
				if (i < row - 1 && j >= 1 && board[i + 1][j - 1] == 1)
					count++;
				if (i < row - 1 && board[i + 1][j] == 1)
					count++;
				if (i < row - 1 && j < col - 1 && board[i + 1][j + 1] == 1)
					count++;

				if (board[i][j] == 0)
				{
					if (count == 3)
						result[i][j] = 1;
				}
				else
				{
					if (count < 2)
						result[i][j] = 0;
					else if (count <= 3)
						result[i][j] = 1;
					else
						result[i][j] = 0;
				}
			}
		}
		board = result;
	}
};

int main()
{
	Solution *solution = new Solution;
	vector<vector<int>> input = {
		{0,1,0},
		{0,0,1},
		{1,1,1},
		{0,0,0}
	};
	solution->gameOfLife(input);
	
	delete solution;
	system("pause");
	return 0;
}