//Given an array of size n, find the majority element.The majority element is the element that appears more than ⌊ n / 2 ⌋ times.
//
//You may assume that the array is non - empty and the majority element always exist in the array.

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
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> map;
		int result = 0;
		for (int num : nums)
		{
			if (map.count(num))
			{
				map[num]++;
			}
			else
			{
				map[num] = 1;
			}
			result = map[result] < map[num] ? num : result;
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 2, 2, 1, 1, 1, 2, 2 };
	auto result = solution->majorityElement(input);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
