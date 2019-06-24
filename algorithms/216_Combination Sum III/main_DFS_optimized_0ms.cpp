//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

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
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int> out = {};
		combinationSum3DFS(result, out, k, n, 0, 0, 0);
		return result;
	}

	void combinationSum3DFS(vector<vector<int>> &result, vector<int> &out, int k, int n, int sum, int cur, int index) {
		if (sum > n || index > k)
			return;
		if (sum == n && index == k)
		{
			result.push_back(out);
			return;
		}
		for (int i = cur + 1; i < 10; ++i)
		{
			sum += i;
			if (sum > n)
				return;
			out.push_back(i);
			combinationSum3DFS(result, out, k, n, sum, i, index + 1);
			sum -= i;
			out.pop_back();
		}
	}

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->combinationSum3(3, 7);
	result = solution->combinationSum3(3, 9);
	/*cout << result << endl;*/
	delete solution;
	system("pause");
	return 0;
}