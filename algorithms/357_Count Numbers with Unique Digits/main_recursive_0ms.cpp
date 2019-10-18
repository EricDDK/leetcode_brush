//Given a non - negative integer n, count all numbers with unique digits, x, where 0 ¡Ü x < 10n.

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
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0)
			return 1;
		int result = 0;
		for (int i = 1; i <= n; ++i)
		{
			result += path(i);
		}
		return result;
	}

	int path(int k)
	{
		if (k < 1) 
			return 0;
		if (k == 1)
			return 10;
		int result = 1;
		for (int i = 9; i >= (11 - k); --i) {
			result *= i;
		}
		return result * 9;
	}

};

int main()
{
	Solution *solution = new Solution;
	for (int i = 2; i < 6; ++i)
	{
		int result = solution->countNumbersWithUniqueDigits(i);
		int aaa = 1;
	}
	delete solution;
	system("pause");
	return 0;
}