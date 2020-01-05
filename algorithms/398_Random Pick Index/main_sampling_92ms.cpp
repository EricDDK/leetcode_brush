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
		v = nums;
	}

	int pick(int target) {
		int cnt = 0, result = -1;
		for (int i = 0; i < v.size(); ++i)
		{
			if (target != v[i])
				continue;
			++cnt;
			if (rand() % cnt == 0)
				result = i;
		}
		return result;
	}

	vector<int> v;
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