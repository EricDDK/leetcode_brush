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
			if (n % 26 == 0)
			{
				result += 'Z';
				n -= 26;
			}
			else
			{
				result += n % 26 - 1 + 'A';
				n -= n % 26;
			}
			n /= 26;
		}
		reverse(result.begin(), result.end());
		return result;
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
