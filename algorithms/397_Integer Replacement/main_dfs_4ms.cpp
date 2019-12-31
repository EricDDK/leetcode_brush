//Given a positive integer n and you can do operations as follow :
//
//If n is even, replace n with n / 2.
//If n is odd, you can replace n with either n + 1 or n - 1.
//What is the minimum number of replacements needed for n to become 1 ?

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
	int integerReplacement(int n) {
		if (n == 1)
			return 0;
		if (n % 2 == 0)
			return 1 + integerReplacement(n / 2);
		else
		{
			long long t = n;
			return 2 + min(integerReplacement((t - 1) / 2), integerReplacement((t + 1) / 2));
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->integerReplacement(8);
	if (result != 3)
		throw;
	result = solution->integerReplacement(7);
	if (result != 4)
		throw;
	result = solution->integerReplacement(65535);
	if (result != 17)
		throw;
	delete solution;
	system("pause");
	return 0;
}