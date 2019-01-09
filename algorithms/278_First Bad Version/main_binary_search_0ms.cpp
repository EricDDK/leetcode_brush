//You are a product manager and currently leading a team to develop a new product.Unfortunately, the latest version of your product fails the quality check.Since each version is developed based on the previous version, all the versions after a bad version are also bad.
//
//Suppose you have n versions[1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
//
//You are given an API bool isBadVersion(version) which will return whether version is bad.Implement a function to find the first bad version.You should minimize the number of calls to the API.

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

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int left = 1, right = n;
		int mid;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (isBadVersion(mid))
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		return left;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->firstBadVersion(5);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}