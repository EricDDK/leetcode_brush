//Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

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
	void wiggleSort(vector<int>& nums) {
		vector<int> tmp = nums;
		int n = nums.size(), k = (n + 1) / 2, j = n;
		sort(tmp.begin(), tmp.end());
		for (int i = 0; i < n; ++i) 
		{
			nums[i] = i & 1 ? tmp[--j] : tmp[--k];
		}
	}
};

int main()
{
	Solution *solution = new Solution;
	vector<int> input;
	//
	input = { 1, 5, 1, 1, 6, 4 };
	solution->wiggleSort(input);
	input = { 1, 3, 2, 2, 3, 1 };
	solution->wiggleSort(input);
	//
	delete solution;
	system("pause");
	return 0;
}