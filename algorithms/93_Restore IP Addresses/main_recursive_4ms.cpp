//Given a string containing only digits, restore it by returning all possible valid IP address combinations.

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
	vector<string> restoreIpAddresses(string s) {
		if (s.empty() || s.size() < 4)
			return {};
		vector<string> result;
		restoreIpAddressesDFS(s ,result, "", 4);
		return result;
	}

	void restoreIpAddressesDFS(string s, vector<string> &result, string out, int index) {
		if (index == 0)
		{
			if (s.empty())
			{
				result.push_back(out);
			}
		}
		else
		{
			for (int i = 1; i <= 3; ++i)
			{
				if (s.size() >= i && isValid(s.substr(0, i)))
				{
					if (index == 1)
					{
						restoreIpAddressesDFS(s.substr(i), result, out + s.substr(0, i), index - 1);
					}
					else
					{
						restoreIpAddressesDFS(s.substr(i), result, out + s.substr(0, i) + ".", index - 1);
					}
				}
			}
		}
	}

	bool isValid(string s) {
		if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) 
			return false;
		int res = atoi(s.c_str());
		return res <= 255 && res >= 0;
	}

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->restoreIpAddresses("25525511135");
	//cout << result << endl
	delete(solution);
	system("pause");
	return 0;
}