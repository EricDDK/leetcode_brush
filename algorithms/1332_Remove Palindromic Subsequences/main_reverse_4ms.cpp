//Given an array of integers arr and an integer d.In one step you can jump from index i to index :
//
//i + x where : i + x < arr.length and 0 < x <= d.
//	i - x where : i - x >= 0 and 0 < x <= d.
//	In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j(More formally min(i, j) < k < max(i, j)).
//
//	You can choose any index of the array and start jumping.Return the maximum number of indices you can visit.
//
//	Notice that you can not jump outside of the array at any time.

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
	int removePalindromeSub(string s) {
		return s.empty() ? 0 : s == string(s.rbegin(), s.rend()) ? 1 : 2;
	}

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->removePalindromeSub("ababa");
	if (result != 1)
		throw;
	result = solution->removePalindromeSub("abb");
	if (result != 2)
		throw;
	result = solution->removePalindromeSub("baabb");
	if (result != 2)
		throw;
	result = solution->removePalindromeSub("");
	if (result != 0)
		throw;
	delete solution;
	system("pause");
	return 0;
}