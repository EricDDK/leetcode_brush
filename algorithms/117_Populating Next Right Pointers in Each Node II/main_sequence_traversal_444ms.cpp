//Given a binary tree
//
//struct Node {
//	int val;
//	Node *left;
//	Node *right;
//	Node *next;
//}
//Populate each next pointer to point to its next right node.If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class Solution {
public:
	Node* connect(Node* root) {
		if (!root)
			return NULL;
		queue<Node*> q;
		q.push(root);
		while (!q.empty())
		{
			Node* pre = NULL;
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				Node* tmp = q.front();
				q.pop();
				if (tmp->left)
				{
					if (pre)
						pre->next = tmp->left;
					q.push(tmp->left);
					pre = tmp->left;
				}
				if (tmp->right)
				{
					if (pre)
						pre->next = tmp->right;
					q.push(tmp->right);
					pre = tmp->right;
				}
			}
		}
		return root;
	}
};

int main()
{
	Solution* solution = new Solution;
	Node* input = new Node(1, NULL, NULL, NULL);
	input->left = new Node(2, NULL, NULL, NULL);
	input->right = new Node(3, NULL, NULL, NULL);
	input->left->left = new Node(4, NULL, NULL, NULL);
	input->left->right = new Node(5, NULL, NULL, NULL);
	input->right->right = new Node(7, NULL, NULL, NULL);
	auto result = solution->connect(input);
	delete(solution);
	system("pause");
	return 0;
}