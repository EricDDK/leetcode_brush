//Given a non - empty array of numbers, a0, a1, a2, …, an - 1, where 0 ≤ ai < 231.
//
//	Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
//
//	Could you do this in O(n) runtime ?

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
	int findMaximumXOR(vector<int>& nums) {
		int result = 0;
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				result = max((nums[i] ^ nums[j]), result);
			}
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->findMaximumXOR(vector<int>{3,10,5,25,2,8});
	if (result != 28)
		throw;
	delete solution;
	system("pause");
	return 0;
}