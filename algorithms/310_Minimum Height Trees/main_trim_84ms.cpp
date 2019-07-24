//For an undirected graph with tree characteristics, we can choose any node as the root.The result graph is then a rooted tree.Among all possible rooted trees, those with minimum height are called minimum height trees(MHTs).Given such a graph, write a function to find all the MHTs and return a list of their root labels.
//
//Format
//The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges(each edge is a pair of labels).
//
//You can assume that no duplicate edges will appear in edges.Since all edges are undirected, [0, 1] is the same as[1, 0] and thus will not appear together in edges.

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
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n == 1)
			return { 0 };
		unordered_map<int, unordered_set<int>> graph;
		for (auto& e : edges)
		{
			graph[e[0]].insert(e[1]);
			graph[e[1]].insert(e[0]);
		}
		vector<int> leaves;
		for (auto& p : graph)
		{
			if (p.second.size() == 1)
				leaves.push_back(p.first);
		}
		while (n > 2)
		{
			vector<int> v;
			for (int i : leaves)
			{
				int next = *graph[i].begin();
				auto it = graph.find(next);
				it->second.erase(i);
				if (it->second.size() == 1)
					v.push_back(next);
			}
			n -= leaves.size();
			v.swap(leaves);
		}
		return leaves;
	}
};

int main()
{
	Solution *solution = new Solution;
	vector<vector<int>> input = {
		{1, 0},
		{ 1, 2 },
		{ 1, 3 },
	};
	if (solution->findMinHeightTrees(4, input)[0] != 1)
		throw;
	delete solution;
	system("pause");
	return 0;
}