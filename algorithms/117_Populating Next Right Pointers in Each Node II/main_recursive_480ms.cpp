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
		Node* p = root->next;
		while (p)
		{
			if (p->left)
			{
				p = p->left;
				break;
			}
			if (p->right)
			{
				p = p->right;
				break;
			}
			p = p->next;
		}
		if (root->left)
			root->left->next = root->right ? root->right : p;
		if (root->right)
			root->right->next = p;
		connect(root->right);
		connect(root->left);
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