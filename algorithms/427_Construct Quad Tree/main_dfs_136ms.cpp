//We want to use quad trees to store an N x N boolean grid.Each cell in the grid can only be true or false.The root node represents the whole grid.For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same.
//
//Each node has another two boolean attributes : isLeaf and val.isLeaf is true if and only if the node is a leaf node.The val attribute for a leaf node contains the value of the region it represents.
//
//Your task is to use a quad tree to represent a given grid.The following example may help you understand the problem better :
//
//Given the 8 x 8 grid below, we want to construct the corresponding quad tree :

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
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};

class Solution {
public:
	Node* construct(vector<vector<int>>& grid) {
		int n = grid.size();
		if (n == 0)
			return NULL;
		return dfs(grid, 0, 0, n);
	}

	Node* dfs(vector<vector<int>>& grid, int x, int y, int size) {
		if (size <= 0) 
			return NULL;
		for (int i = x; i < x + size; ++i)
		{
			for (int j = y; j < y + size; ++j)
			{
				if (grid[i][j] != grid[x][y])
				{
					return new Node(true, false,
						dfs(grid, x, y, size / 2),
						dfs(grid, x, y + size / 2, size / 2),
						dfs(grid, x + size / 2, y, size / 2),
						dfs(grid, x + size / 2, y + size / 2, size / 2)
					);
				}
			}
		}
		return new Node(grid[x][y] == 1, true, NULL, NULL, NULL, NULL);
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->construct(vector<vector<int>>{
		vector<int>{1, 1, 1, 1, 0, 0, 0, 0},
		vector<int>{1, 1, 1, 1, 0, 0, 0, 0},
		vector<int>{1, 1, 1, 1, 1, 1, 1, 1},
		vector<int>{1, 1, 1, 1, 1, 1, 1, 1},
		vector<int>{1, 1, 1, 1, 0, 0, 0, 0},
		vector<int>{1, 1, 1, 1, 0, 0, 0, 0},
		vector<int>{1, 1, 1, 1, 0, 0, 0, 0},
		vector<int>{1, 1, 1, 1, 0, 0, 0, 0}
	});
	delete solution;
	system("pause");
	return 0;
}