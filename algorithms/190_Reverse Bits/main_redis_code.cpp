//Given an array, rotate the array to the right by k steps, where k is non - negative.

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
	uint32_t reverseBits(uint32_t n) {
		unsigned s = 8 * sizeof(n);
		uint32_t mask = ~0;
		while ((s = s >> 1) > 0) {
			mask ^= mask << s;
			n = ((n >> s) & mask) | ((n << s) & (~mask));
		}
		return n;
	}
};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	uint32_t input = stoi("43261596");
	solution->reverseBits(input);
	//cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
