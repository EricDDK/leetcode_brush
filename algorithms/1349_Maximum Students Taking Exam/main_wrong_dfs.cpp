//Given a m * n matrix seats  that represent seats distributions in a classroom.If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character.
//
//Students can see the answers of those sitting next to the left, right, upper left and upper right, but he cannot see the answers of the student sitting directly in front or behind him.Return the maximum number of students that can take the exam together without any cheating being possible..
//
//Students must be placed in seats in good condition.

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
	int maxStudents(vector<vector<char>>& seats) {
		int m = seats.size(), n = seats[0].size();
		vector<vector<char>> ss = seats;
		int max1 = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (seats[i][j] == '.')
				{
					max1 += dfs1(ss, i, j, m, n);
				}
			}
		}
		int max2 = 0;
		ss = seats;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (seats[j][i] == '.')
				{
					max2 += dfs2(ss, i, j, m, n);
				}
			}
		}
		return max(max1, max2);
	}

	int dfs1(vector<vector<char>>& seats, int i, int j, int m, int n) {
		if (j - 1 >= 0 && seats[i][j - 1] == '!')
			return 0;
		if (j + 1 < n && seats[i][j + 1] == '!')
			return 0;
		if (i - 1 >= 0 && j - 1 >= 0 && seats[i - 1][j - 1] == '!')
			return 0;
		if (i + 1 < m && j + 1 < n && seats[i + 1][j + 1] == '!')
			return 0;
		seats[i][j] = '!';
		return 1;
	}

	int dfs2(vector<vector<char>>& seats, int j, int i, int m, int n) {
		if (j - 1 >= 0 && seats[i][j - 1] == '!')
			return 0;
		if (j + 1 < n && seats[i][j + 1] == '!')
			return 0;
		if (i - 1 >= 0 && j - 1 >= 0 && seats[i - 1][j - 1] == '!')
			return 0;
		if (i + 1 < m && j + 1 < n && seats[i + 1][j + 1] == '!')
			return 0;
		seats[i][j] = '!';
		return 1;
	}

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->maxStudents(vector<vector<char>>{
		vector<char>{'#', '.', '#', '#', '.', '#'},
		vector<char>{'.', '#', '#', '#', '#', '.'},
		vector<char>{'#', '.', '#', '#', '.', '#'},
	});
	if (result != 4)
		throw;
	result = solution->maxStudents(vector<vector<char>>{
		vector<char>{'.', '#'},
		vector<char>{'#', '#'},
		vector<char>{'#', '.'},
		vector<char>{'#', '#'},
		vector<char>{'.', '#'},
	});
	if (result != 3)
		throw;
	result = solution->maxStudents(vector<vector<char>>{
		vector<char>{'#', '.', '.', '.', '#'},
		vector<char>{'.', '#', '.', '#', '.'},
		vector<char>{'.', '.', '#', '.', '.'},
		vector<char>{'.', '#', '.', '#', '.'},
		vector<char>{'#', '.', '.', '.', '#'},
	});
	if (result != 10)
		throw;
	delete solution;
	system("pause");
	return 0;
}