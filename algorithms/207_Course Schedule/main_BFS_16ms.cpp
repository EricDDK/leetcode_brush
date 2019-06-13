//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
//
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses ?

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses, vector<int>());
		vector<int> inDegree(numCourses, 0);
		for (auto &p : prerequisites)
		{
			graph[p[1]].push_back(p[0]);
			inDegree[p[0]]++;
		}
		queue<int> q;
		for (int i = 0; i < numCourses; ++i) 
		{
			if (inDegree[i] == 0) 
				q.push(i);
		}
		while (!q.empty())
		{
			int t = q.front(); 
			q.pop();
			for (auto& g : graph[t])
			{
				--inDegree[g];
				if (inDegree[g] == 0)
					q.push(g);
			}
		}
		for (int i = 0; i < numCourses; ++i) 
		{
			if (inDegree[i] != 0)
				return false;
		}
		return true;
	}
};

int main() {
	Solution* solution = new Solution;
	vector<vector<int>> input{ {1,0} };
	if (!solution->canFinish(2, input))
		throw;
	input = { {1,0},{0,1} };
	if (solution->canFinish(2, input))
		throw;
	input = { {1,0},{2,1} };
	if (!solution->canFinish(3, input))
		throw;
	delete(solution);
	system("pause");
	return 0;
}