//Given a 32 - bit signed integer, reverse digits of an integer.

#include "iostream"
#include <vector>
#include <unordered_map>
#include "windows.h"

using namespace std;

class Solution {
public:
	int reverse(int x) {
		int result = 0;
		while (x != 0)
		{
			if (abs(result) > INT_MAX / 10)
			{
				return 0;
			}
			result = result * 10 + x % 10;
			x /= 10;
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->reverse(-123);
	delete solution;
	system("pause");
	return 0;
}
