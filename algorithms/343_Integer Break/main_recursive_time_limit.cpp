//Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers.\
//Return the maximum product you can get.

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
	int integerBreak(int n) {
		if (n == 3 || n == 2)
			return n - 1;
		int result = 1;
		integerBreakDFS(n, 1, result);
		return result;
	}

	void integerBreakDFS(int n, int tmp, int& result) {
		if (n < 2)
		{
			result = max(tmp, result);
			return;
		}
		for (int i = 2; i <= n; ++i)
		{
			tmp *= i;
			integerBreakDFS(n - i, tmp, result);
			tmp /= i;
		}
	}

};

int main()
{
	Solution *solution = new Solution;
	if (solution->integerBreak(3) != 2)
		throw;
	if (solution->integerBreak(2) != 1)
		throw;
	if (solution->integerBreak(10) != 36)
		throw;
	delete solution;
	system("pause");
	return 0;
}