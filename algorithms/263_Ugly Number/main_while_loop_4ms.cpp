//Write a program to check whether a given number is an ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

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
	bool isUgly(int num) {
		if (num == 0)
		{
			return false;
		}
		if (num == 1)
		{
			return true;
		}
		while (num % 2 == 0)
		{
			num /= 2;
		}
		while (num % 3 == 0)
		{
			num /= 3;
		}
		while (num % 5 == 0)
		{
			num /= 5;
		}
		return num == 1;
	}
};

int main()
{
	Solution* solution = new Solution;
	
	auto result = solution->isUgly(6);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}