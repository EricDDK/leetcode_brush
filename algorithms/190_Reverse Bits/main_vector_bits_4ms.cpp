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
		vector<int> bits;
		uint32_t result = 0;
		for (int i = 0; i < 32; i++)
		{
			bits.push_back(n % 2);
			n /= 2;
		}
		for (int i = 0; i < 32; i++)
		{
			result = result * 2 + bits[i];
		}
		return result;
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
