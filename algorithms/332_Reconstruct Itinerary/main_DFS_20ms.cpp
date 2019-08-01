//One way to serialize a binary tree is to use pre - order traversal.When we encounter a non - null node, 
//we record the node's value. If it is a null node, we record using a sentinel value such as #.

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
	void bt(unordered_map<string, map<string, int>>& graph,
		vector<string>& cpath, string st, int remain, bool& found) {
		if (remain == 0) {
			found = true;
			return;
		}
		for (auto& next : graph[st]) {
			if (next.second == 0)
				continue;
			next.second--;
			cpath.push_back(next.first);
			bt(graph, cpath, next.first, remain - 1, found);
			if (!found) {
				cpath.pop_back();
				next.second++;
			}
		}
	}
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		unordered_map<string, map<string, int>> graph;
		for (auto& t : tickets) {
			graph[t[0]][t[1]]++;
		}
		vector<string> rpath;
		vector<string> cpath;
		cpath.push_back("JFK");
		bool found = false;
		bt(graph, cpath, "JFK", tickets.size(), found);
		return cpath;
	}
};

int main()
{
	Solution *solution = new Solution;
	vector<vector<string>> input = {
		{ "MUC", "LHR" },
		{ "JFK", "MUC" },
		{ "SFO", "SJC" },
		{ "LHR", "SFO" },
	};
	auto result = solution->findItinerary(input);
	delete solution;
	system("pause");
	return 0;
}