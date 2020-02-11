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
		int result = 0;
		int out = 0;
		m = seats[0].size();
		n = seats.size();
		dfs(seats, 0, 0, out, result);
		return result;
	}

	void dfs(vector<vector<char>>& seats, int i, int j, int out, int& result) {
		if (j == m)
		{
			i++;
			j = 0;
		}
		if (i == n)
		{
			result = max(result, out);
			return;
		}
		char c = seats[i][j];
		if (seats[i][j] == '.')
		{
			dfs(seats, i, j + 1, out, result);
			// 
			if (
				(j == 0 || i == 0 || seats[i - 1][j - 1] != 'p') &&
				(j == m - 1 || i == 0 || seats[i - 1][j + 1] != 'p') &&
				(j == 0 || seats[i][j - 1] != 'p')
				)
			{
				seats[i][j] = 'p';
				dfs(seats, i, j + 1, out + 1, result);
			}
		}
		else
		{
			dfs(seats, i, j + 1, out, result);
		}
		seats[i][j] = c;
	}

private:
	int m;
	int n;
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