//Given an array nums containing n + 1 integers where each integer is between 1 and n(inclusive), 
//prove that at least one duplicate number must exist.Assume that there is only one duplicate number, find the duplicate one.

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
	int findDuplicate(vector<int>& nums) {
		int left = 0, right = nums.size() - 1, mid = 0;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			int count = 0;
			for (int& n : nums)
			{
				if (n <= mid)
					count++;
			}
			if (count <= mid)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return left;
	}
};

int main()
{
	Solution *solution = new Solution;
	vector<int> input = {1,3,4,2,2};
	if (solution->findDuplicate(input) != 2)
		throw;
	input = {3,1,3,4,2};
	if (solution->findDuplicate(input) != 3)
		throw;
	input = {2,2,2,2,2};
	if (solution->findDuplicate(input) != 2)
		throw;
	delete solution;
	system("pause");
	return 0;
}