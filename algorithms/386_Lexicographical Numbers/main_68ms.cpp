//Given an integer n, return 1 - n in lexicographical order.
//
//For example, given 13, return: [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9].
//
//Please optimize your algorithm to use less time and space.The input size may be as large as 5, 000, 000.

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
	vector<int> lexicalOrder(int n) {
		vector<int> res(n);
		int cur = 1;
		for (int i = 0; i < n; ++i) 
		{
			res[i] = cur;
			if (cur * 10 <= n) 
			{
				cur *= 10;
			}
			else 
			{
				if (cur >= n) 
					cur /= 10;
				cur += 1;
				while (cur % 10 == 0) 
					cur /= 10;
			}
		}
		return res;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->lexicalOrder(200);
	delete solution;
	system("pause");
	return 0;
}