//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

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

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int size = nums.size();
		if (size < 2)
			return;
		int index = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0)
			{
				nums[index++] = nums[i];
			}
		}
		while (index < nums.size())
		{
			nums[index++] = 0;
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 2,1 };
	/*auto result = */solution->moveZeroes(input);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}