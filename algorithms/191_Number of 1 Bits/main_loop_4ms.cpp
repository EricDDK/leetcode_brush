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
	int hammingWeight(uint32_t n) {
		int result = 0;
		while (n > 0)
		{
			if ((n & 1) == 1)
			{
				result++;
			}
			n >>= 1;
		}
		return result;
	}
};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	uint32_t input = stoi("11");
	solution->hammingWeight(input);
	//cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
