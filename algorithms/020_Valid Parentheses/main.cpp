//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Note that an empty string is also considered valid.

#include "iostream"
#include <vector>
#include <unordered_map>
#include "windows.h"
#include "algorithm"
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> myStack;

		for (char &c : s){
			if (c == '('){
				myStack.push(')');
			}
			else if (c == '{'){
				myStack.push('}');
			}
			else if (c == '['){
				myStack.push(']');
			}
			else{
				if (myStack.empty() || myStack.top() != c){
					return 0;
				}
				else{
					myStack.pop();
				}
			}
		}

		return myStack.empty() ? 1 : 0;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->isValid("{[]}");
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
