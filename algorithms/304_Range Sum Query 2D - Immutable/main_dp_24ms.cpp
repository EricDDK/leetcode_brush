//Given a 2D matrix matrix, find the sum of the elements inside the 
//rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

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

class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) 
			return;
		dp.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
		for (int i = 1; i <= matrix.size(); ++i)
		{
			for (int j = 1; j <= matrix[0].size(); ++j)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
	}

private:
	vector<vector<int>> dp;
};

int main()
{
	vector<vector<int>> input = {
		{ 3, 0, 1, 4, 2 },
		{ 5, 6, 3, 2, 1 },
		{ 1, 2, 0, 1, 5 },
		{ 4, 1, 0, 1, 7 },
		{ 1, 0, 3, 0, 5 }
	};
	NumMatrix nn(input);
	if (nn.sumRegion(2, 1, 4, 3) != 8)
		throw;
	if (nn.sumRegion(1, 1, 2, 2) != 11)
		throw;
	if (nn.sumRegion(1, 2, 2, 4) != 12)
		throw;
	system("pause");
	return 0;
}