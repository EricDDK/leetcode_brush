//Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
		int *dp = new int[n + 1]();
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		int result = dp[n];
		delete[] dp;
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->numTrees(3);
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}