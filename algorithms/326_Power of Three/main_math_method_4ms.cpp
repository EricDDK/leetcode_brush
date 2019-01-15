//Given an integer array nums, find the sum of the elements between indices i and j(i ≤ j), inclusive.

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
	bool isPowerOfThree(int n) {
		return (n > 0 && 1162261467 % n == 0);
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->isPowerOfThree(45);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}