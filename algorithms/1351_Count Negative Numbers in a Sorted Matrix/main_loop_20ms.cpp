//Given a m * n matrix grid which is sorted in non - increasing order both row - wise and column - wise.
//
//Return the number of negative numbers in grid.

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
	int countNegatives(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		int result = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] < 0)
				{
					result += (m - j);
					break;
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	
	delete solution;
	system("pause");
	return 0;
}