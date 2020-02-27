//Given an integer array arr.You have to sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
//
//Return the sorted array.

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
#include <numeric>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

bool cmp(int& a, int& b) {
	int m = 0, n = 0;
	for (int i = 0; i < 32; ++i)
	{
		m += ((a >> i) & 1);
		n += ((b >> i) & 1);
	}
	if (m == n)
		return a < b;
	return m < n;
}

class Solution {
public:
	vector<int> sortByBits(vector<int>& arr) {
		sort(arr.begin(), arr.end(), cmp);
		return arr;
	}

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->sortByBits(vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8});
	/*if (result != "BANC")
		throw;*/
	delete solution;
	system("pause");
	return 0;
}