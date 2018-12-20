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
		vector<int> result;
		for (int i = 0; i < numbers.size(); ++i)
		{
			for (int j = i+1; j < numbers.size(); j++)
			{
				int tmp = numbers[i] + numbers[j];
				if (tmp == target)
				{
					return{ i+1,j+1 };
				}
				if (tmp > target)
				{
					break;
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { -1,0 };
	auto result = solution->twoSum(input, -1);
	//cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
