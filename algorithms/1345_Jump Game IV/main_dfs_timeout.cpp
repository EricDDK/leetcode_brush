

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
	int minJumps(vector<int>& arr) {
		int n = arr.size();
		if (n <= 1)
			return 0;
		if (n == 2)
			return 1;
		int result = INT_MAX;
		vector<bool> visited(n, false);
		dfs(arr, 0, 0, result, visited);
		return result;
	}

	void dfs(vector<int>& arr, int index, int out, int& result, vector<bool>& visited) {
		if (index == arr.size() - 1)
		{
			result = min(result, out);
			return;
		}
		if (visited[index])
			return;
		visited[index] = true;
		if (index - 1 >= 0)
			dfs(arr, index - 1, out + 1, result, visited);
		if (index + 1 < arr.size())
			dfs(arr, index + 1, out + 1, result, visited);
		for (int i = 1; i < arr.size(); ++i)
		{
			if (arr[index] == arr[i])
				dfs(arr, i, out + 1, result, visited);
		}
		visited[index] = false;
	}

private:
	
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->minJumps(vector<int>{100, -23, -23, 404, 100, 23, 23, 23, 3, 404});
	if (result != 3)
		throw;
	result = solution->minJumps(vector<int>{7});
	if (result != 0)
		throw;
	result = solution->minJumps(vector<int>{7, 6, 9, 6, 9, 6, 9, 7});
	if (result != 1)
		throw;
	result = solution->minJumps(vector<int>{6, 1, 9});
	if (result != 2)
		throw;
	result = solution->minJumps(vector<int>{11, 22, 7, 7, 7, 7, 7, 7, 7, 22, 13});
	if (result != 3)
		throw;
	result = solution->minJumps(vector<int>{68, -94, -44, -18, -1, 18, -87, 29, -6, -87, -27, 37, -57, 7, 18, 68, -59, 29, 7, 53, -27, -59, 18, -1, 18, -18, -59, -1, -18, -84, -20, 7, 7, -87, -18, -84, -20, -27});
	delete solution;
	system("pause");
	return 0;
}