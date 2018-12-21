//Given a column title as appear in an Excel sheet, return its corresponding column number.

#include "iostream"
#include "math.h"
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
	int titleToNumber(string s) {
		int result = 0;
		int carry = 1;
		for (int i = s.size()-1; i >= 0; --i)
		{
			result += (s[i] - 'A' + 1) * carry;
			carry *= 26;
		}
		return result;
	}
};

int main()
{
	Solution s;
	Solution* solution = new Solution;
	auto result = solution->titleToNumber("ZY");
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
