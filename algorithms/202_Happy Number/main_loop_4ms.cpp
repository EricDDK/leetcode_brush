//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process : Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

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
	bool isHappy(int n) {
		long long result = 0;
		unordered_map<int, int> map;
		map[n] = -1;
		while (true)
		{
			int tmp = n;
			while (tmp != 0)
			{
				result += (tmp % 10)* (tmp % 10);
				tmp /= 10;
			}
			if (result == 1)
			{
				return true;
			}
			if (map.count(result))
			{
				return false;
			}
			else
			{
				map[result] = -1;
			}
			n = result;
			result = 0;
		}
		return false;
	}

};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	auto result = solution->isHappy(2);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
