//There is a list of sorted integers from 1 to n.Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
//
//Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.
//
//We keep repeating the steps again, alternating left to right and right to left, until a single number remains.
//
//Find the last number that remains starting with a list of length n.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include "windows.h"
#include <algorithm>
#include <stack>
#include <string>
#include <queue>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Solution {
public:
	int lastRemaining(int n) {
		return help(n, true);
	}
	int help(int n, bool left2right) {
		if (n == 1) return 1;
		if (left2right) {
			return 2 * help(n / 2, false);
		}
		else {
			return 2 * help(n / 2, true) - 1 + n % 2;
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->lastRemaining(8);
	delete solution;
	system("pause");
	return 0;
}