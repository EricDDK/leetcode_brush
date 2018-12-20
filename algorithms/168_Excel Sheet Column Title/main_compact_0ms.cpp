//Given a positive integer, return its corresponding column title as appear in an Excel sheet.

#include "iostream"
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
	string convertToTitle(int n)
	{
		string result = "";
		while (n)
		{
			result += --n % 26 + 'A';
			n /= 26;
		}
		return string(result.rbegin(), result.rend());
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->convertToTitle(28);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
