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
		unordered_map<int, int> map;
		register int index = 0;
		for (int num : numbers)
		{
			map[num] = index++;
		}
		for (int i = 0; i < numbers.size(); i++)
		{
			if (map.count(target - numbers[i]))
			{
				return{ i+1, map[target - numbers[i]]+1 };
			}
		}
		return {};
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 2,7,11,15 };
	auto result = solution->twoSum(input, 9);
	//cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
