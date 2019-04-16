//You are climbing a stair case.It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
//
//Note : Given n will be a positive integer.

#include "iostream"
#include <vector>
#include <unordered_map>
#include <map>
#include <hash_set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int a = 1, b = 1;
		while (n--)
		{
			b += a;
			a = b - a;
		}
		return a;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->climbStairs(5);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
