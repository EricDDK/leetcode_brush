//Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

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
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> hashmap;
		for (int i = 0; i < nums.size(); i++)
		{
			if (hashmap.count(nums[i]) && i - hashmap[nums[i]] <= k)
				return true;
			hashmap[nums[i]] = i;
		}
		return false;
	}
};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	vector<int> input = { 1, 0, 1, 1 };
	auto result = solution->containsNearbyDuplicate(input, 1);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}