//You are given a doubly linked list which in addition to the next and previous pointers, 
//it could have a child pointer, which may or may not point to a separate doubly linked list.
//These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.
//
//Flatten the list so that all the nodes appear in a single - level, doubly linked list.You are given the head of the first level of the list.

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
	Node* prev;
	Node* next;
	Node* child;
};

class Solution {
public:
	Node* flatten(Node* head) {
		Node* cur = head;
		while (cur)
		{
			if (cur->child)
			{
				Node *next = cur->next;
				cur->child = flatten(cur->child);
				Node *last = cur->child;
				while (last->next) 
					last = last->next;
				cur->next = cur->child;
				cur->next->prev = cur;
				cur->child = NULL;
				last->next = next;
				if (next) 
					next->prev = last;
			}
			cur = cur->next;
		}
		return cur;
	}
};

int main()
{
	Solution* solution = new Solution;
	
	delete solution;
	system("pause");
	return 0;
}