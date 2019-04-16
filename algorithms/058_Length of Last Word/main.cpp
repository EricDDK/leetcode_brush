//Given an integer array nums, find the contiguous subarray(containing at least one number) which has the largest sum and return its sum.

#include "iostream"
#include <vector>
#include <unordered_map>
#include <map>
#include <hash_set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int result = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != ' ')
			{
				if (i != 0 && s[i - 1] == ' ')
				{
					result = 1;
				}
				else
				{
					result++;
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->lengthOfLastWord("b   a    ");
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
