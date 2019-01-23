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
		if (num == 1) 
			return true;
		int min = num / 2, max = num/2;
		while (min * min > num)
		{

		}
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