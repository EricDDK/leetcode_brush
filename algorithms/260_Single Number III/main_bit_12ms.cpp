//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
//Find the two elements that appear only once.

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
	vector<int> singleNumber(vector<int>& nums) {
		int diff = 0;
		for (auto& n : nums)
		{
			diff ^= n;
		}
		diff &= -diff;
		vector<int> result(2, 0);
		for (auto& n : nums)
		{
			if (diff & n)
				result[0] ^= n;
			else
				result[1] ^= n;
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = {1,2,1,3,2,5};
	auto result = solution->singleNumber(input);
	if (result.size() != 2 || result[0] != 3 || result[1] != 5)
		throw;
	delete solution;
	system("pause");
	return 0;
}