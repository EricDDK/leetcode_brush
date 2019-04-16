//Given a non - empty array of digits representing a non - negative integer, plus one to the integer.
//
//The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//
//You may assume the integer does not contain any leading zero, except the number 0 itself.

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
	vector<int> plusOne(vector<int>& digits) {
		if (digits.empty())
		{
			return digits;
		}
		digits[digits.size() - 1]++;
		for (int i = digits.size()-1; i >= 0; --i)
		{
			if (digits[i] == 10)
			{
				digits[i] = 0;
				if (i>0)
				{
					digits[i - 1]++;
				}
			}
		}
		if (digits[0] == 0 || digits[0] == 10)
		{
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = { 9,9 };
	auto result = solution->plusOne(input);
	//cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
