//Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
//
//Note:
//n is positive and will fit within the range of a 32 - bit signed integer(n < 2^31).

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
	int findNthDigit(int n) {
		long base = 9, digits = 1;
		while (n - base * digits > 0)
		{
			n -= base * digits;
			base *= 10;
			digits++;
		}
		int index = n % digits;
		if (index == 0)
			index = digits;
		long num = 1;
		for (int i = 1; i < digits; i++)
			num *= 10;
		num += (index == digits) ? n / digits - 1 : n / digits;;
		for (int i = index; i < digits; i++)
			num /= 10;
		return num % 10;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->findNthDigit(3);
	if (result != 3)
		throw;
	result = solution->findNthDigit(11);
	if (result != 0)
		throw;
	result = solution->findNthDigit(250);
	if (result != 1)
		throw;
	delete solution;
	system("pause");
	return 0;
}