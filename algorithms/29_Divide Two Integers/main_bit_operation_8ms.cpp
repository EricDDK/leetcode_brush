//Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
//Return the quotient after dividing dividend by divisor.
//
//The integer division should truncate toward zero.

#include<sstream>
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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) 
			return INT_MAX;
		long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
		if (n == 1) 
			return sign == 1 ? m : -m;
		while (m >= n) 
		{
			long long t = n, p = 1;
			while (m >= (t << 1)) {
				t <<= 1;
				p <<= 1;
			}
			res += p;
			m -= t;
		}
		return sign == 1 ? res : -res;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->divide(-1, 1);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}