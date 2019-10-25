//Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

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
	// 1337 10100111001
	int superPow(int a, vector<int>& b) 
	{
		long long res = 1;
		for (int i = 0; i < b.size(); ++i) {
			res = pow(res, 10) * pow(a, b[i]) % 1337;
		}
		return res;
	}
	int pow(int x, int n) 
	{
		if (n == 0) return 1;
		if (n == 1) return x % 1337;
		return pow(x % 1337, n / 2) * pow(x % 1337, n - n / 2) % 1337;
	}
};

int main()
{
	Solution *solution = new Solution;
	auto result = solution->superPow(2, vector<int>{3});
	if (result != 8)
		throw;
	result = solution->superPow(2, vector<int>{1, 0});
	if (result != 1024)
		throw;
	delete solution;
	system("pause");
	return 0;
}