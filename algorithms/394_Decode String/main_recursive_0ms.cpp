//Given an encoded string, return its decoded string.
//
//The encoding rule is : k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.Note that k is guaranteed to be a positive integer.
//
//You may assume that the input string is always valid; No extra white spaces, square brackets are well - formed, etc.
//
//Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.For example, there won't be input like 3a or 2[4].

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include "windows.h"
#include <algorithm>
#include <stack>
#include <string>
#include <queue>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Solution {
public:
	string decodeString(string s) {
		int i = 0;
		return decode(s, i);
	}

	string decode(string s, int& i) {
		string result = "";
		int n = s.size();
		while (i < n && s[i] != ']')
		{
			if (s[i] < '0' || s[i] > '9')
			{
				result += s[i++];
			}
			else
			{
				int cnt = 0;
				while (s[i] >= '0' && s[i] <= '9')
				{
					cnt = cnt * 10 + (s[i++] - '0');
				}
				i++;
				string tmp = decode(s, i);
				i++;
				while (cnt-- > 0)
				{
					result += tmp;
				}
			}
		}
		return result;
	}

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->decodeString("3[a]2[bc]");
	if (result != "aaabcbc")
		throw;
	result = solution->decodeString("3[a2[c]]");
	if (result != "accaccacc")
		throw;
	result = solution->decodeString("2[abc]3[cd]ef");
	if (result != "abcabccdcdcdef")
		throw;
	delete solution;
	system("pause");
	return 0;
}