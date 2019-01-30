//Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
//Return the quotient after dividing dividend by divisor.
//
//The integer division should truncate toward zero.

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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int size = nums.size();
		int mid = size - 2;
		for (int i = 1; i < size; ++i)
		{
			if (nums[i] < nums[i - 1])
			{
				mid = i - 2;
				break;
			}
		}
		for (int i = size - 1; i >= 0; --i)
		{
			if (nums[i] > nums[mid])
			{
				swap(nums[mid], nums[i]);
				reverse(nums.begin() + mid + 1, nums.end());
				break;
			}
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 1,2 };
	/*auto result = */solution->nextPermutation(input);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}