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
#include <functional>

using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		string result;
		vector<string> v;
		for (auto &i : nums)
			v.push_back(to_string(i));
		sort(v.begin(), v.end(), [](string& s1, string& s2) 
		{
			return s1 + s2 > s2 + s1;
		}
		);
		for (auto& s : v)
		{
			result.append(s);
		}
		if (!result.empty() && result[0] == '0')
			return "0";
		return result;
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