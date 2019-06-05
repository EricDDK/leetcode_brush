//Given a list of non negative integers, arrange them such that they form the largest number.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

int getDigitNum(int num)
{
	unsigned int count = 10;
	while (num >= 10)
	{
		num = num / 10;
		count *= 10;
	}
	return count;
}

bool compare(int &a, int &b)
{
	long long product1 = (long long)a * (getDigitNum(b)) + b;
	long long product2 = (long long)b * (getDigitNum(a)) + a;
	return product1 < product2;
}

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		string result;
		vector<vector<int>> v(10, vector<int>());
		int tmp, i, j;
		for (i = 0; i < nums.size(); ++i)
		{
			tmp = getFirstBit(nums[i]);
			v[tmp].push_back(nums[i]);
		}
		for (i = 9; i >= 0; --i)
		{
			sort(v[i].begin(), v[i].end(), compare);
			for (j = v[i].size() - 1; j >= 0; --j)
			{
				result.append(to_string(v[i][j]));
			}
		}
		if (!result.empty() && result[0] == '0')
			return "0";
		return result;
	}

	int getFirstBit(int num)
	{
		while (num >= 10)
		{
			num = num / 10;
		}
		return num;
	}

};

int main() {
	Solution solution;
	vector<int> input = { 10,2 };
	if (solution.largestNumber(input) != "210")
		throw;
	input = { 3,30,34,5,9 };
	if (solution.largestNumber(input) != "9534330")
		throw;
	input = { 999999998,999999997,999999999 };
	if (solution.largestNumber(input) != "999999999999999998999999997")
		throw;
	input = { 1,2,3,4,5,6,7,8,9,0 };
	if (solution.largestNumber(input) != "9876543210")
		throw;
	input = { 0,0 };
	if (solution.largestNumber(input) != "0")
		throw;
	input = { 1,0,0 };
	if (solution.largestNumber(input) != "100")
		throw;
	system("pause");
	return 0;
}