//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//getMin() --Retrieve the minimum element in the stack.

#include "iostream"
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

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		s1.push(x);
		if (s2.empty() || s2.top() >= x)
		{
			s2.push(x);
		}
	}

	void pop() {
		if (s2.top() == s1.top())
		{
			s2.pop();
		}
		s1.pop();
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return s2.top();
	}
private:
	stack<int> s1, s2;
};

int main()
{
	MinStack obj = new MinStack();
	obj.push(5);
	obj.pop();
	int param_3 = obj.top();
	int param_4 = obj.getMin();
	system("pause");
	return 0;
}
