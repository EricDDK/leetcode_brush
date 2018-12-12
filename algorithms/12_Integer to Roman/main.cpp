//Roman numerals are represented by seven different symbols : I, V, X, L, C, D and M.
//
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//
//Roman numerals are usually written largest to smallest from left to right.However, the numeral for four is not IIII.Instead, the number four is written as IV.Because the one is before the five we subtract it making four.The same principle applies to the number nine, which is written as IX.There are six instances where subtraction is used :
//
//I can be placed before V(5) and X(10) to make 4 and 9.
//X can be placed before L(50) and C(100) to make 40 and 90.
//C can be placed before D(500) and M(1000) to make 400 and 900.
//Given an integer, convert it to a roman numeral.Input is guaranteed to be within the range from 1 to 3999.

#include "iostream"
#include <vector>
#include <unordered_map>
#include "windows.h"
#include "algorithm"

using namespace std;

auto __ = []()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
	string intToRoman(int num) {
		string temp;
		unordered_map<int, string> map;
		map[1] = "I";
		map[4] = "IV";
		map[5] = "V";
		map[9] = "IX";
		map[10] = "X";
		map[40] = "XL";
		map[50] = "L";
		map[90] = "XC";
		map[100] = "C";
		map[400] = "CD";
		map[500] = "D";
		map[900] = "CM";
		map[1000] = "M";
		vector<int> key;
		for (auto s : map)
		{
			key.push_back(s.first);
		}
		sort(key.begin(), key.end(), [](int a, int b){return a>b; });
		char buff[80];
		for (int i = 0; i<key.size(); i++)
		{
			int times = num / key[i];
			for (int j = 0; j<times; j++)
			{
				temp += map[key[i]];
			}
			num -= (times*key[i]);
		}
		return temp;
	}
};
int main()
{
	Solution* solution = new Solution;
	auto result = solution->intToRoman(1994);
	delete solution;
	system("pause");
	return 0;
}
