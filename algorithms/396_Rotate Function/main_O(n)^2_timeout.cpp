﻿//Given an array of integers A and let n to be its length.
//
//Assume Bk to be an array obtained by rotating the array A k positions clock - wise, we define a "rotation function" F on A as follow :
//
//F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n - 1) * Bk[n - 1].
//
//Calculate the maximum value of F(0), F(1), ..., F(n - 1).

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
	int maxRotateFunction(vector<int>& A) {
		int n = A.size();
		int result = 0;
		for (int i = 0; i < n; ++i)
		{
			result = max(result, maxRotateFunction(A, i, n));
		}
		return result;
	}

	int maxRotateFunction(vector<int>& A, int index, int n) {
		int i = 0, j = 0;
		int res = 0;
		for (i = index; i < n; ++i)
		{
			res += A[j++] * i;
		}
		for (i = 0; i < index; ++i)
		{
			res += A[j++] * i;
		}
		return res;
	}

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->maxRotateFunction(vector<int>{4,3,2,6});
	if (result != 26)
		throw;
	result = solution->maxRotateFunction(vector<int>{-2147483648, -2147483648});
	if (result != -2147483648)
		throw;
	delete solution;
	system("pause");
	return 0;
}