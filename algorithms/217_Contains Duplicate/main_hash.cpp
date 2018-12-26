//Reverse a singly linked list.

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
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> map;
		for (auto &num : nums)
		{
			if (map.count(num))
			{
				return true;
			}
			map[num] = 0;
		}
		return false;
	}
};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	vector<int> input = { 1, 2, 3, 1 };
	auto result = solution->containsDuplicate(input);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}