//Determine whether an integer is a palindrome.An integer is a palindrome when it reads the same backward as forward.

#include "iostream"
#include <vector>
#include <unordered_map>
#include "windows.h"

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0)) return false;
		int revertNum = 0;
		while (x > revertNum) {
			revertNum = revertNum * 10 + x % 10;
			x /= 10;
		}
		return x == revertNum || x == revertNum / 10;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->isPalindrome(-121);
	delete solution;
	system("pause");
	return 0;
}
