//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.

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
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		generateParenthesisDFS(n, n, "", result);
		return result;
	}

	void generateParenthesisDFS(int left, int right, string out, vector<string> &res)
	{
		if (left > right)
		{
			return;
		}
		if (left == 0 && right == 0)
		{
			res.push_back(out);
		}
		else
		{
			if (left > 0)
			{
				generateParenthesisDFS(left - 1, right, out + '(', res);
			}
			if (right > 0)
			{
				generateParenthesisDFS(left, right -1, out + ')', res);
			}
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->generateParenthesis(3);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}