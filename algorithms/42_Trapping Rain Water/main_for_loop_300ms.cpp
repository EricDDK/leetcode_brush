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
		int result = 0;
		int leftMax = 0, rightMax = 0;
		for (int i = 0; i < height.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				leftMax = max(height[j], leftMax);
			}
			for (int j = i + 1; j < height.size(); ++j)
			{
				rightMax = max(height[j], rightMax);
			}
			int tmp = (min(leftMax, rightMax) - height[i]);
			result += tmp > 0 ? tmp : 0;
			leftMax = rightMax = 0;
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
	delete solution;
	system("pause");
	return 0;
}