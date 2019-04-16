//Given an array nums and a value val, remove all instances of that value in - place and return the new length.
//
//Do not allocate extra space for another array, you must do this by modifying the input array in - place with O(1) extra memory.
//
//The order of elements can be changed.It doesn't matter what you leave beyond the new length.

#include "iostream"
#include <vector>
#include <unordered_map>
#include <hash_set>
#include "windows.h"
#include "algorithm"
#include <stack>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty())
		{
			return 0;
		}
		vector<int>::iterator it;
		for (it = nums.begin(); it != nums.end();)
		{
			if (val == *it)
			{
				it = nums.erase(it);
			}
			else
			{
				++it;
			}
		}
		return nums.size();
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 0, 1, 2, 2, 3, 0, 4, 2 };
	auto result = solution->removeElement(input, 2);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
