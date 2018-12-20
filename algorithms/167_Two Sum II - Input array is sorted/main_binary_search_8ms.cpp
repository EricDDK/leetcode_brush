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
		for (int i = 0; i < numbers.size(); ++i)
		{
			int div = target - numbers[i];
			int left = i+1;
			int right = numbers.size();
			while (left < right)
			{
				int mid = left + (right - left) / 2;
				if (numbers[mid] == div)
				{
					return{ i + 1, mid + 1 };
				}
				else if (numbers[mid] < div)
				{
					left = mid+1;
				}
				else
				{
					right = mid;
				}
			}
		}
		return{};
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
