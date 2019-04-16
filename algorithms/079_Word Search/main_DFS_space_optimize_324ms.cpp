//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, 
//where "adjacent" cells are those horizontally or vertically neighboring.The same letter cell may not be used more than once.

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
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty()) 
			return false;
		int row = board.size();
		int col = board[0].size();
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (existDFS(board, word, 0, i, j))
					return true;
			}
		}
		return false;
	}

	bool existDFS(vector<vector<char>>& board, string word, int index, int i, int j) {
		if (index == word.size())
			return true;
		int row = board.size();
		int col = board[0].size();
		if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] != word[index])
			return false;
		char c = board[i][j];
		board[i][j] = '#';
		bool result = existDFS(board, word, index + 1, i - 1, j)
			|| existDFS(board, word, index + 1, i + 1, j)
			|| existDFS(board, word, index + 1, i, j + 1)
			|| existDFS(board, word, index + 1, i, j - 1);
		board[i][j] = c;
		return result;
	}

};

int main()
{
	Solution* solution = new Solution;
	vector<vector<char>> input = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	auto result = solution->exist(input, "ABCCED");
	//cout << result << endlsearchMatrix
	delete(solution);
	system("pause");
	return 0;
}