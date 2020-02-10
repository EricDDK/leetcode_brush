//Given an n - ary tree, return the level order traversal of its nodes' values.
//
//Nary - Tree input serialization is represented in their level order traversal, each group of children is separated by the null value(See examples).

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
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> result;
		if (root == NULL)
			return result;
		queue<Node*> q;
		q.push(root);

		while (!q.empty())
		{
			vector<int> v;
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				Node* tmp = q.front();
				q.pop();
				v.push_back(tmp->val);
				for (auto t : tmp->children)
				{
					q.push(t);
				}
			}
			result.push_back(v);
		}

		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	Node* root = new Node(1);
	root->children = vector<Node*>{ new Node(3), new Node(2), new Node(4) };
	root->children[0]->children = vector<Node*>{ new Node(5), new Node(6) };
	auto result = solution->levelOrder(root);
	delete solution;
	system("pause");
	return 0;
}