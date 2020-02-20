//Given a m * n matrix mat of integers, sort it diagonally in ascending order from the top - left to the bottom - right then return the sorted array.

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
#include <numeric>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
	{
		for (int k = 0; k + 1 < mat.size(); k++)
			for (int i = 0; i + 1 < mat.size(); i++)
				for (int j = 0; j + 1 < mat[i].size(); j++)
					if (mat[i][j] > mat[i + 1][j + 1])
						swap(mat[i][j], mat[i + 1][j + 1]);
		return mat;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->diagonalSort(vector<vector<int>>{
		{ 3,3,1,1 },
		{ 2,2,1,2 },
		{ 1,1,1,2 }
	});
	delete solution;
	system("pause");
	return 0;
}