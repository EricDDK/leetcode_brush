//Write a program to find the node at which the intersection of two singly linked lists begins.

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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0;
		int right = numbers.size() - 1;
		while (left < right)
		{
			if (numbers[left] + numbers[right] == target)
			{
				return {left+1,right+1};
			}
			else if (numbers[left] + numbers[right] < target)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 2,3,4 };
	auto result = solution->twoSum(input, 6);
	//cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
