//Implement int sqrt(int x).
//
//Compute and return the square root of x, where x is guaranteed to be a non - negative integer.
//
//Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

#include "iostream"
#include <vector>
#include <unordered_map>
#include <map>
#include <hash_set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1)
		{
			return x;
		}
		int x1 = x;
		int x2 = x / 2;
		while ((x1-x2) > 0)
		{
			x1 = x2;
			x2 = (x1 + x / x1) / 2;
		}
		return x1;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->mySqrt(0);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
