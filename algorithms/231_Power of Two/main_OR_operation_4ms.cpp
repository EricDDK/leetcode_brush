//Given an integer, write a function to determine if it is a power of two.

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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n > 0 && ((n & (n - 1)) == 0))
		{
			return true;
		}
		return false;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->isPowerOfTwo(16);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}