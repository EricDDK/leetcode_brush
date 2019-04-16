//The gray code is a binary numeral system where two successive values differ in only one bit.
//
//Given a non - negative integer n representing the total number of bits in the code, print the sequence of gray code.A gray code sequence must begin with 0.

#include <sstream>
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
	vector<int> grayCode(int n) {
		vector<int> result;
		for (int i = 0; i < pow(2, n); ++i) {
			result.push_back((i >> 1) ^ i);
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->grayCode(2);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}