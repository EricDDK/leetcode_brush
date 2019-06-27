//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non - negative integers, +, -, *, / operators and empty spaces.The integer division should truncate toward zero.

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

class Solution {
public:
	int calculate(string s) {
		long res = 0, num = 0, n = s.size();
		char op = '+';
		stack<int> st;
		for (int i = 0; i < n; ++i) 
		{
			if (s[i] >= '0') 
			{
				num = num * 10 + s[i] - '0';
			}
			if ((s[i] < '0' && s[i] != ' ') || i == n - 1) 
			{
				if (op == '+')
					st.push(num);
				if (op == '-') 
					st.push(-num);
				if (op == '*' || op == '/') 
				{
					int tmp = (op == '*') ? st.top() * num : st.top() / num;
					st.pop();
					st.push(tmp);
				}
				op = s[i];
				num = 0;
			}
		}
		while (!st.empty()) 
		{
			res += st.top();
			st.pop();
		}
		return res;
	}
};

int main()
{
	Solution* solution = new Solution;
	if (solution->calculate("1*2-3/4+5*6-7*8+9/10") != -24)
		throw;
	if (solution->calculate("0-2147483647") != -2147483647)
		throw;
	if (solution->calculate("1337") != 1337)
		throw;
	if (solution->calculate("42") != 42)
		throw;
	if (solution->calculate("3+2*2") != 7)
		throw;
	if (solution->calculate(" 3/2 ") != 1)
		throw;
	if (solution->calculate(" 3+5 / 2 ") != 5)
		throw;
	delete solution;
	system("pause");
	return 0;
}