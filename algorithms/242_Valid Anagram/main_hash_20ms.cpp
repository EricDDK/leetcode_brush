//Lowest Common Ancestor of a Binary Search Tree

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
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
		{
			return false;
		}
		unordered_map<char, int> map;
		for (auto &str : s)
		{
			if (map.count(str))
			{
				map[str]++;
				continue;
			}
			map[str] = 1;
		}
		for (auto &str : t)
		{
			if (!map.count(str))
			{
				return false;
			}
			else
			{
				if (--(map[str]) < 0)
				{
					return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->isAnagram("anagram","nagaram");
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}