

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
		unordered_map<int, vector<int>> indicesOfValue;
		for (int i = 0; i < n; i++)
			indicesOfValue[arr[i]].push_back(i);
		vector<bool> visited(n); 
		visited[0] = true;
		queue<int> q;
		q.push(0);
		int step = 0;
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				int t = q.front();
				q.pop();
				if (t == n - 1)
					return step;
				vector<int>& next = indicesOfValue[arr[t]];
				next.push_back(t - 1);
				next.push_back(t + 1);
				for (auto j : next)
				{
					if (j >= 0 && j < n && !visited[j])
					{
						visited[j] = true;
						q.push(j);
					}
				}
				next.clear();
			}
			step++;
		}
		return 0;
	}

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