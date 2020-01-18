//Given a reference of a node in a connected undirected graph.
//
//Return a deep copy(clone) of the graph.
//
//Each node in the graph contains a val(int) and a list(List[Node]) of its neighbors.

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

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
};

class Solution {
public:
	Node* cloneGraph(Node* node) {
		unordered_map<Node*, Node*> m;
		return dfs(node, m);
	}

	Node* dfs(Node* node, unordered_map<Node*, Node*>& m) {
		if (!node)
			return NULL;
		if (m.count(node))
			return m[node];
		Node* clone = new Node(node->val);
		m[node] = clone;
		for (auto& n : node->neighbors)
		{
			clone->neighbors.push_back(dfs(n, m));
		}
		return clone;
	}

};

int main()
{
	Solution* solution = new Solution;
	
	delete solution;
	system("pause");
	return 0;
}