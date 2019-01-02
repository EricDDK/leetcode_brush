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
		int a[26] = { 0 };
		for (int i = 0; i < s.size(); ++i)
		{
			a[s[i] - 'a']++;
			a[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++)
		{
			if (a[i] < 0)
			{
				return false;
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