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
		if (nums.empty() || (k %= nums.size()) == 0)
		{
			return;
		}
		int size = nums.size();
		reverse(nums.begin(), nums.begin() + size - k);
		reverse(nums.begin() + size - k, nums.end());
		reverse(nums.begin(), nums.end());
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
