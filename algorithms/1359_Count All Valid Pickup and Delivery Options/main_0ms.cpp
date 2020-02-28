//Given a string s consisting only of characters a, b and c.
//
//Return the number of substrings containing at least one occurrence of all these characters a, b and c.

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
#include <numeric>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Solution {
public:
	int countOrders(int n) {
		long long p = 1;
		for (int i = 1; i <= n * 2; i++)
		{
			p *= i % 2 ? i : i / 2;
			p %= 1000000007;
		}
		return (int)p;
	}
};

int main()
{
	Solution* solution = new Solution;

	delete solution;
	system("pause");
	return 0;
}