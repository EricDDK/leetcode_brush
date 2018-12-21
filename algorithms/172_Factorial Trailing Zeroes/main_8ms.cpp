//Given an integer n, return the number of trailing zeroes in n!.

#include "iostream"
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
	int trailingZeroes(int n) {
		int result = 0;
		while (n)
		{
			result += n / 5;
			n /= 5;
		}
		return result;
	}
};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	auto result = solution->trailingZeroes(1808548329);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
