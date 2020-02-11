

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
	int numOfSubarrays(vector<int>& arr, int k, int threshold) {
		int n = arr.size(), result = 0;
		int t = k * threshold;
		vector<int> dp(n + 1, 0);
		for (int i = 0; i < n; ++i)
			dp[i + 1] = dp[i] + arr[i];
		for (int i = 0; i + k <= n; ++i)
		{
			if (dp[i + k] - dp[i] >= t)
				++result;
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	//auto result = solution->numOfSubarrays(vector<int>{11, 13, 17, 23, 29, 31, 7, 5, 2, 3}, 3, 5);
	auto result = solution->numOfSubarrays(vector<int>{2, 2, 2, 2, 5, 5, 5, 8}, 3, 4);
	delete solution;
	system("pause");
	return 0;
}