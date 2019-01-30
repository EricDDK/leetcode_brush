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

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		int i, j, n = num.size();
		for (i = n - 2; i >= 0; --i) 
		{
			if (num[i + 1] > num[i]) 
			{
				for (j = n - 1; j > i; --j) 
				{
					if (num[j] > num[i]) break;
				}
				swap(num[i], num[j]);
				reverse(num.begin() + i + 1, num.end());
				return;
			}
		}
		reverse(num.begin(), num.end());
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