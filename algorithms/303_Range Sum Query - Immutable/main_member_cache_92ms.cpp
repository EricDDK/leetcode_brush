//Given an integer array nums, find the sum of the elements between indices i and j(i ≤ j), inclusive.

#include<sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums) {
		_nums = nums;
	}

	int sumRange(int i, int j) {
		int result = 0;
		while (i <= j)
		{
			result += _nums[i++];
		}
		return result;
	}

	vector<int> _nums;
};

int main()
{
	vector<int> input = { -2, 0, 3, -5, 2, -1 };
	NumArray* ss = new NumArray(input);
	auto result = ss->sumRange(0,2);
	/*Solution* solution = new Solution;
	auto result = solution->canWinNim(4);
	cout << result << endl;*/
	delete(ss);
	system("pause");
	return 0;
}