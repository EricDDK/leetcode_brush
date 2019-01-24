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
			return {};
		vector<string> result;
		string dict[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		operateLetters(result, digits, 0, "", dict);
		return result;
	}

	void operateLetters(vector<string> &result, string digits, int index, string res, string dict[])
	{
		if (index == digits.size())
		{
			result.push_back(res);
			return;
		}
		string str = dict[digits[index] - '0'];
		for (int i = 0; i < str.size(); ++i)
		{
			operateLetters(result, digits, index + 1, res + string(1, str[i]), dict);
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->letterCombinations("23");
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}