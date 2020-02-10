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
		for (int i = 0; i < arr.size(); ++i)
		{
			long long n = arr[i] * 2;
			for (int j = 0; j < arr.size(); ++j)
			{
				if (i != j && n == arr[j])
					return true;
			}
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