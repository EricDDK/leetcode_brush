//Implement the following operations of a stack using queues.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//empty() --Return whether the stack is empty.

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

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
		for (int i = 0; i < q.size() - 1; ++i)
		{
			q.push(q.front()); q.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int x = q.front(); q.pop();
		return x;
	}

	/** Get the top element. */
	int top() {
		return q.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}

private:
	queue<int> q;
};

int main()
{
	MyStack obj;
	obj.push(1);
	int param_2 = obj.pop();
	int param_3 = obj.top();
	bool param_4 = obj.empty();
	system("pause");
	return 0;
}