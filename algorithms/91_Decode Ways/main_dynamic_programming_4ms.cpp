//A message containing letters from A - Z is being encoded to numbers using the following mapping :
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Given a non - empty string containing only digits, determine the total number of ways to decode it.
//
//Example 1:
//
//Input: "12"
//	Output : 2
//	Explanation : It could be decoded as "AB" (1 2) or "L" (12).
//	Example 2 :
//
//	Input : "226"
//	Output : 3
//	Explanation : It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

#include <sstream>
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
	int numDecodings(string s) {
		if (s.empty() || (s.size() > 1 && s[0] == '0')) 
			return 0;
		vector<int> dp(s.size() + 1, 0);
		dp[0] = 1;
		for (int i = 1; i < dp.size(); ++i)
		{
			dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
			if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
			{
				dp[i] += dp[i - 2];
			}
		}
		return dp.back();
	}
};

int main()
{
	Solution* solution = new Solution;
	if (solution->numDecodings("0") != 0)
		cout << "error" << endl;
	if (solution->numDecodings("12") != 2)
		cout << "error" << endl;
	if (solution->numDecodings("226") != 3)
		cout << "error" << endl;
	if (solution->numDecodings("10") != 1)
		cout << "error" << endl;
	if (solution->numDecodings("27") != 1)
		cout << "error" << endl;
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}