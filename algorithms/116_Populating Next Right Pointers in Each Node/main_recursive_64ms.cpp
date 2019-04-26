//You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.The binary tree has the following definition :

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
		if (root->left)
			root->left->next = root->right;
		if (root->right)
			root->right->next = root->next ? root->next->left : NULL;
		connect(root->left);
		connect(root->right);
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
	input->right->left = new Node(6, NULL, NULL, NULL);
	input->right->right = new Node(7, NULL, NULL, NULL);
	auto result = solution->connect(input);
	delete(solution);
	system("pause");
	return 0;
}