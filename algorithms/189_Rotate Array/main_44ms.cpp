//Given an array, rotate the array to the right by k steps, where k is non - negative.

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
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if (size <= 1)
		{
			return;
		}
		int index = 0;
		for (int i = size - 1; k > 0; --k, --i)
		{
			nums.insert(nums.begin(), nums[i + index]);
			index++;
		}
		nums.resize(size);
	}
};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	vector<int> input = { 1, 2, 3, 4, 5, 6, 7 };
	/*auto result = */solution->rotate(input, 3);
	//cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
