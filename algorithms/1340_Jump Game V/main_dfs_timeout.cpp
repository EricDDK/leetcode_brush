//Given an array of integers arr and an integer d.In one step you can jump from index i to index :
//
//i + x where : i + x < arr.length and 0 < x <= d.
//	i - x where : i - x >= 0 and 0 < x <= d.
//	In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j(More formally min(i, j) < k < max(i, j)).
//
//	You can choose any index of the array and start jumping.Return the maximum number of indices you can visit.
//
//	Notice that you can not jump outside of the array at any time.

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
	int maxJumps(vector<int>& arr, int d) {
		int result = 0;
		n = arr.size();
		vector<int> visited(n, -1);
		for (int i = 0; i < arr.size(); ++i)
		{
			dfs(arr, d, i, 1, visited, result);
		}
		return result;
	}

	void dfs(const vector<int>& arr, int d, int index, int out, vector<int>& visited, int& result) {
		if (visited[index] >= 0)
		{
			result = max(result, out + visited[index]);
			return;
		}
		bool no = false;
		for (int i = ((index - d) >= 0 ? (index - d) : 0); i < n && i <= index + d; ++i)
		{
			if (arr[index] > arr[i])
			{
				bool can = true;
				for (int j = min(i, index) + 1; j < max(i, index); ++j)
				{
					if (arr[j] >= arr[index] || arr[i] >= arr[index])
					{
						can = false;
						break;
					}
				}
				if (can)
				{
					dfs(arr, d, i, out + 1, visited, result);
					no = true;
				}
			}
		}
		if (!no)
		{
			visited[index] = 0;
			result = max(result, out);
		}
	}

private:
	int n;
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->maxJumps(vector<int>{6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12}, 2);
	if (result != 4)
		throw;
	result = solution->maxJumps(vector<int>{7, 6, 5, 4, 3, 2, 1}, 1);
	if (result != 7)
		throw;
	delete solution;
	system("pause");
	return 0;
}