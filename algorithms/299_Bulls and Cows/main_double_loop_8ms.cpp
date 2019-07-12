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
	string getHint(string secret, string guess) {
		int m[256] = { 0 }, bulls = 0, cows = 0;
		for (int i = 0; i < secret.size(); ++i)
		{
			if (secret[i] == guess[i]) 
				++bulls;
			else 
				++m[secret[i]];
		}
		for (int i = 0; i < secret.size(); ++i) 
		{
			if (secret[i] != guess[i] && m[guess[i]]) 
			{
				++cows;
				--m[guess[i]];
			}
		}
		return to_string(bulls) + "A" + to_string(cows) + "B";
	}
};

int main()
{
	Solution *solution = new Solution;
	if (solution->getHint("1807", "7810") != "1A3B")
		throw;
	if (solution->getHint("1123", "0111") != "1A1B")
		throw;
	delete solution;
	system("pause");
	return 0;
}