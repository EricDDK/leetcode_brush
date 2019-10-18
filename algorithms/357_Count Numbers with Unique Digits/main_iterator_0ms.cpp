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
		int result = 10, cnt = 9;
		for (int i = 2; i <= n; ++i)
		{
			cnt *= (11 - i);
			result += cnt;
		}
		return result;
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