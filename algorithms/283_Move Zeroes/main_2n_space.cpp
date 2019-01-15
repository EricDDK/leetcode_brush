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
		if (nums.size() < 2)
		{
			return;
		}
		vector<int> v1 = {};
		vector<int> v2 = {};
		for (int num : nums)
		{
			if (num == 0)
				v2.push_back(num);
			else
				v1.push_back(num);
		}
		v1.insert(v1.end(), v2.begin(), v2.end());
		nums = v1;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 0, 1, 0, 3, 12 };
	/*auto result = */solution->moveZeroes(input);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}