//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".

#include "iostream"
#include <vector>
#include <unordered_map>
#include "windows.h"
#include "algorithm"

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result = "";
		if (strs.size() == 0) return result;
		if (strs.size() == 1) return strs[0];

		int j = 0;
		bool isSame = true;
		while (true)
		{
			for (int i = 0; i < strs.size() - 1; ++i)
			{
				if (strs[i][j] != strs[i + 1][j])
				{
					isSame = false;
					break;
				}
			}
			if (!isSame)
			{
				break;
			}
			j++;
		}
		result = strs[0].substr(0, j);
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<string> inputs = { "flower", "flow", "flight" };
	auto result = solution->longestCommonPrefix(inputs);
	delete solution;
	system("pause");
	return 0;
}
