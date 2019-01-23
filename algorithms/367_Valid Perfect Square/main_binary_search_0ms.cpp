//Given two arrays, write a function to compute their intersection.

#include<sstream>
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
	bool isPerfectSquare(int num) 
	{
		int high = 46340, low = 0, mid;
		while (low <= high) {

			mid = low + (high - low) / 2;

			if (mid*mid > num) {
				high = mid - 1;
			}
			else if (mid*mid < num) {
				low = mid + 1;
			}
			else {
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->isPerfectSquare(14);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}