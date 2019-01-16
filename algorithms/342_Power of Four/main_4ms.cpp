//Given an integer(signed 32 bits), write a function to check whether it is a power of 4.

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
	bool isPowerOfFour(int num) {
		return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->isPowerOfFour(2);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}