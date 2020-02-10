//Given an array arr of integers, check if there exists two integers N and M such that N is the double of M(i.e.N = 2 * M).
//
//More formally check if there exists two indices i and j such that :

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
	bool checkIfExist(vector<int>& arr) {
		unordered_set<int> s;
		for (auto& a : arr)
		{
			if (s.count(2 * a) || (a % 2 == 0 && s.count(a / 2)))
				return true;
			s.insert(a);
		}
		return false;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->checkIfExist(vector<int>{-2, 0, 10, -19, 4, 6, -8});
	if (result)
		throw;
	delete solution;
	system("pause");
	return 0;
}