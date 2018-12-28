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
		q2.push(x);
		while (q2.size() > 1) 
		{
			q1.push(q2.front()); q2.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int x = top(); 
		q2.pop();
		return x;
	}

	/** Get the top element. */
	int top() {
		if (q2.empty())
		{
			for (int i = 0; i < (int)q1.size() - 1; ++i) 
			{
				q1.push(q1.front()); q1.pop();
			}
			q2.push(q1.front()); q1.pop();
		}
		return q2.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty() && q2.empty();
	}

private:
	queue<int> q1, q2;
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