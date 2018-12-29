//Implement Queue using Stacks

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

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		while (s2.size() > 0)
		{
			int v = s2.top();
			s2.pop();
			s1.push(v);
		}
		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		while (s1.size() > 0)
		{
			int v = s1.top();
			s1.pop();
			s2.push(v);
		}
		int result = s2.top();
		s2.pop();
		return result;
	}

	/** Get the front element. */
	int peek() {
		while (s1.size() > 0)
		{
			int v = s1.top();
			s1.pop();
			s2.push(v);
		}
		return s2.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s1.empty() && s2.empty();
	}
private:
	stack<int>s1, s2;
};

int main()
{
	MyQueue obj;
	obj.push(5);
	int param_2 = obj.pop();
	int param_3 = obj.peek();
	bool param_4 = obj.empty();
	system("pause");
	return 0;
}