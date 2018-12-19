//Given a non - empty array of integers, every element appears twice except for one.Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?

#include "iostream"
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

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		for (int i = 1; i < nums.size(); ++i)
		{
			nums[0] ^= nums[i];
		}
		return nums[0];
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = {4,1,2,1,2};
	auto result = solution->singleNumber(input);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
