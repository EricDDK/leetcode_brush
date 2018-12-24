//Count the number of prime numbers less than a non - negative number, n.

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
	int countPrimes(int n) {
		int res = 0;
		vector<bool> prime(n, true);
		for (int i = 2; i < n; ++i)
		{
			if (prime[i])
			{
				res++;
				for (int j = 2; i * j < n; ++j)
				{
					prime[i * j] = false;
				}
			}
		}
		return res;
	}

};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	auto result = solution->countPrimes(499979);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}