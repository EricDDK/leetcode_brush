//Roman numerals are represented by seven different symbols : I, V, X, L, C, D and M.
//
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
//Given a roman numeral, convert it to an integer.Input is guaranteed to be within the range from 1 to 3999.

#include "iostream"
#include <vector>
#include <unordered_map>
#include "windows.h"
#include "algorithm"

using namespace std;

class Solution {
public:
	Solution()
	{

	}

	int romanToInt(string s) {
		int ret = 0;

		for (unsigned int i = 0; i < s.size(); i++)
		{
			bool bnext = (i + 1 < s.size());
			char next = '\0';
			if (bnext)
				next = s[i + 1];

			switch (s[i])
			{
			case 'I':
				if (bnext && next == 'V')
				{
					ret += 4;
					i++;
				}
				else if (bnext && next == 'X')
				{
					ret += 9;
					i++;
				}
				else
					ret += 1;
				break;
			case 'X':
				if (bnext && next == 'L')
				{
					ret += 40;
					i++;
				}
				else if (bnext && next == 'C')
				{
					ret += 90;
					i++;
				}
				else
					ret += 10;
				break;
			case 'C':
				if (bnext && next == 'D')
				{
					ret += 400;
					i++;
				}
				else if (bnext && next == 'M')
				{
					ret += 900;
					i++;
				}
				else
					ret += 100;
				break;
			case 'V':
				ret += 5;
				break;
			case 'L':
				ret += 50;
				break;
			case 'D':
				ret += 500;
				break;
			case 'M':
				ret += 1000;
				break;
			}
		}
		return ret;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->romanToInt("MCMXCIV");
	delete solution;
	system("pause");
	return 0;
}
