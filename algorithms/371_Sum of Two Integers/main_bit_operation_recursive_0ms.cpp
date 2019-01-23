//Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

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
	int getSum(int a, int b) {
		if (b == 0)
		{
			return a;
		}
		int sum = a ^ b;
		int carry = (a & b) << 1;
		return getSum(sum, carry);
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->getSum(1, 2);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}