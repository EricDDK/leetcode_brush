//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

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
	int trap(vector<int>& height) {
		if (height.empty())
			return 0;
		int n = height.size();
		int result = 0;
		vector<int> lmax(n), rmax(n);
		lmax[0] = height[0];
		height[n - 1] = height[n - 1];
		for (int i = 1; i < n; ++i)
		{
			lmax[i] = max(lmax[i - 1], height[i]);
		}
		for (int i = n - 2; i >= 0; --i)
		{
			rmax[i] = max(rmax[i + 1], height[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			int tmp = min(lmax[i], rmax[i]) - height[i];
			result += tmp > 0 ? tmp : 0;
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->trap(vector<int>{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 });
	if (result != 6)
		throw;
	result = solution->trap(vector<int>{ 2,0,2 });
	if (result != 2)
		throw;
	delete solution;
	system("pause");
	return 0;
}