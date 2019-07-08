//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
//Find the two elements that appear only once.

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
	int nthUglyNumber(int n) {
		static vector<int> v;
		if (v.empty())
		{
			for (long i = 1; i <= INT_MAX; i *= 2)
			{
				for (long j = i; j <= INT_MAX; j *= 3)
				{
					for (long k = j; k <= INT_MAX; k *= 5)
					{
						v.push_back(k);
					}
				}
			}
			sort(v.begin(), v.end());
		}
		return v[n - 1];
	}

};

int main()
{
	Solution* solution = new Solution;
	if (solution->nthUglyNumber(10) != 12)
		throw;
	if (solution->nthUglyNumber(1) != 1)
		throw;
	
	delete solution;
	system("pause");
	return 0;
}