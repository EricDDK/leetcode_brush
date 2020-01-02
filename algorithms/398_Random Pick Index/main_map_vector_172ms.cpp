//Given an array of integers with possible duplicates, randomly output the index of a given target number.You can assume that the given target number must exist in the array.
//
//Note:
//The array size can be very large.Solution that uses too much extra space will not pass the judge.

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
	Solution(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i)
		{
			m[nums[i]].push_back(i);
		}
	}

	int pick(int target) {
		if (m[target].size() <= 1)
			return m[target][0];
		int index = rand() % (m[target].size());
		return m[target][index];
	}

	map<int, vector<int>> m;
};

int main()
{
	//Solution* solution = new Solution;
	Solution* solution = new Solution(vector<int>{1,2,3,3,3});
	int a = solution->pick(3);
	auto result = solution->pick(1);
	if (result != 0)
		throw;
	delete solution;
	system("pause");
	return 0;
}