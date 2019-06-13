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
		vector<int> visit(numCourses);
		for (auto p : prerequisites)
		{
			graph[p[1]].push_back(p[0]);
		}
		for (int i = 0; i < numCourses; i++)
		{
			if (!canFinishDFS(graph, visit, i))
				return false;
		}
		return true;
	}

	// visit -1 conflict , 0 not visit, 1 has visited
	bool canFinishDFS(vector<vector<int>>& graph, vector<int>& visit, int i) {
		if (visit[i] == -1)
			return false;
		if (visit[i] == 1)
			return true;
		visit[i] = -1;
		for (auto g : graph[i])
		{
			if (!canFinishDFS(graph, visit, g))
				return false;
		}
		visit[i] = 1;
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