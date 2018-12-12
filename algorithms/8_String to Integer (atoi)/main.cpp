
//implement atoi which converts a string to an integer.
//
//The function first discards as many whitespace characters as necessary until the first non - whitespace character is found.Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//
//The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//
//If the first sequence of non - whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//
//If no valid conversion could be performed, a zero value is returned.

#include "iostream"
#include <vector>
#include <unordered_map>
#include "windows.h"

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str.empty()) return 0;
		int sign = 1, base = 0, i = 0, n = str.size();
		while (i < n && str[i] == ' ') ++i;
		if (str[i] == '+' || str[i] == '-') {
			sign = (str[i++] == '+') ? 1 : -1;
		}
		while (i < n && str[i] >= '0' && str[i] <= '9') {
			if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
				return (sign == 1) ? INT_MAX : INT_MIN;
			}
			base = 10 * base + (str[i++] - '0');
		}
		return base * sign;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->myAtoi("18446744073709551617");
	delete solution;
	system("pause");
	return 0;
}
