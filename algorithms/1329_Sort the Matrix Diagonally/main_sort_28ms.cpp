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
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		int n = mat.size(), m = mat[0].size();
		vector<int> v;
		for (int index = 0; index < n; ++index)
		{
			v.clear();
			int i = index, j = 0;
			while (i < n && j < m)
			{
				v.push_back(mat[i][j]);
				i++; j++;
			}
			sort(v.begin(), v.end());
			i = index; j = 0;
			while (i < n && j < m)
			{
				mat[i][j] = v[j];
				i++; j++;
			}
		}
		for (int index = 0; index < m; ++index)
		{
			v.clear();
			int i = 0, j = index;
			while (i < n && j < m)
			{
				v.push_back(mat[i][j]);
				i++; j++;
			}
			sort(v.begin(), v.end());
			i = 0; j = index;
			while (i < n && j < m)
			{
				mat[i][j] = v[i];
				i++; j++;
			}
		}
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