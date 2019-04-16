//Given a string containing digits from 2 - 9 inclusive, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters(just like on the telephone buttons) is given below.Note that 1 does not map to any letters.

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
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return{};
		vector<string> res{ "" };
		string dict[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		for (int i = 0; i < digits.size(); ++i)
		{
			vector<string> tmp;
			string str = dict[digits[i] - '0'];
			for (int j = 0; j < str.size(); j++)
			{
				for (auto s : res)
				{
					tmp.push_back(s + str[j]);
				}
			}
			res = tmp;
		}
		return res;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->letterCombinations("2345");
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}