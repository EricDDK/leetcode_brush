// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

#include "iostream"
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		if (board.empty() || board[0].empty()) 
			return false;
		int m = board.size(), n = board[0].size();
        vector<vector<bool> > rowFlag(m, vector<bool>(n, false));
        vector<vector<bool> > colFlag(m, vector<bool>(n, false));
        vector<vector<bool> > cellFlag(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
				if (board[i][j] >= '1' && board[i][j] <= '9'){
					int c = board[i][j] - '1';
					if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c] )
						return false;
					rowFlag[i][c] = true;
					colFlag[c][j] = true;
					cellFlag[3 * (i / 3) + j / 3][c] = true;
				}
			}
		}
		return true;
    }
};

int main()
{
	Solution* solution = new Solution;
	vector<vector<char>> input = {
	{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}};
	auto result = solution->isValidSudoku(input);
	delete solution;
	cout << result << endl;
	return 0;
}
