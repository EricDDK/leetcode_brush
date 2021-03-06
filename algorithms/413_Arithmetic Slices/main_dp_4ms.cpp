﻿//A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//
//For example, these are arithmetic sequence :

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
	int numberOfArithmeticSlices(vector<int>& A) {
		int result = 0, n = A.size();
		vector<int> dp(n, 0);
		for (int i = 2; i < n; ++i)
		{
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
			{
				dp[i] = dp[i - 1] + 1;
			}
			result += dp[i];
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	
	delete solution;
	system("pause");
	return 0;
}