
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
	string simplifyPath(string path) {
		vector<string> vstr;
		int i = 0;
		while (i < path.size())
		{
			while (path[i] == '/' && i < path.size())
				++i;
			if (i == path.size())
				break;
			int start = i;
			while (path[i] != '/' && i < path.size())
				++i;
			int end = i - 1;
			string s = path.substr(start, end - start + 1);
			if (s == "..")
			{
				if (!vstr.empty())
				{
					vstr.pop_back();
				}
			}
			else if (s != ".")
			{
				vstr.push_back(s);
			}
		}
		if (vstr.empty())
			return "/";
		string res;
		for (int i = 0; i < vstr.size(); ++i)
		{
			res += '/' + vstr[i];
		}
		return res;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->simplifyPath("/home/");
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}