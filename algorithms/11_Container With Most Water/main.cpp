//Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and(i, 0).Find two lines, which together with x - axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.

#include "iostream"
#include <vector>
#include <unordered_map>
#include "windows.h"

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0, i = 0, j = height.size() - 1;
		while (i < j)
		{
			res = max(res, min(height[i], height[j]) * (j - i));
			height[i] < height[j] ? ++i : --j;
		}
		return res;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	auto result = solution->maxArea(input);
	delete solution;
	system("pause");
	return 0;
}
