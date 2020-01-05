//Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number(floating point number).Given some queries, return the answers.If the answer does not exist, return -1.0.
//
//Example:
//Given a / b = 2.0, b / c = 3.0.
//queries are : a / c = ? , b / a = ? , a / e = ? , a / a = ? , x / x = ? .
//return[6.0, 0.5, -1.0, 1.0, -1.0].
//
//The input is : vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries, where equations.size() == values.size(), and the values are positive.This represents the equations.Return vector<double>.

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
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		vector<double> result;
		for (int i = 0; i < equations.size(); ++i)
		{
			m[equations[i][0]][equations[i][1]] = values[i];
			m[equations[i][1]][equations[i][0]] = 1.0f / values[i];
		}
		for (auto& q : queries)
		{
			unordered_set<string> visited;
			double t = dfs(q[0], q[1], visited);
			result.push_back(t);
		}
		return result;
	}

	double dfs(string up, string down, unordered_set<string>& visited) {
		if (m[up].count(down))
			return m[up][down];
		for (auto& n : m[up])
		{
			if (visited.count(n.first))
				continue;
			visited.insert(n.first);
			double t = dfs(n.first, down, visited);
			if (t > 0.0f)
				return t * n.second;
		}
		return -1.0f;
	}

	unordered_map<string, unordered_map<string, double>> m;
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->calcEquation(
	vector<vector<string>>
	{
		vector<string>{"a","b"},
		vector<string>{"b", "c"}
	},
	vector<double>{2.0f, 3.0f}, 
	vector<vector<string>>
	{
		vector<string>{"a", "c"},
		vector<string>{"b", "a"},
		vector<string>{"a", "e"},
		vector<string>{"a", "a"},
		vector<string>{"x", "x"}
	});
	delete solution;
	system("pause");
	return 0;
}