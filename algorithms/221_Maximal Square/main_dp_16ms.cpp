//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

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
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int result = 0;
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				if (i == 0 || j == 0)
					dp[i][j] = matrix[i][j] - '0';
				else if (matrix[i][j] == '1')
				{
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
				}
				result = max(result, dp[i][j]);
			}
		}
		return result * result;
	}

};

int main()
{
	Solution* solution = new Solution;
	vector<vector<char>> input = {
		{ '1', '0', '1', '0', '0' },
		{ '1', '0', '1', '1', '1' },
		{ '1', '1', '1', '1', '1' },
		{ '1', '0', '0', '1', '0' }
	};
	if (solution->maximalSquare(input) != 4)
		throw;
	delete solution;
	system("pause");
	return 0;
}