//Given a palindromic string palindrome, replace exactly one character by any lowercase English letter so that the string becomes the lexicographically smallest possible string that isn't a palindrome.
//
//After doing so, return the final string.If there is no way to do so, return the empty string.

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
#include <numeric>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Solution {
public:
	string breakPalindrome(string palindrome) {
		size_t sz = palindrome.size();
		if (sz <= 1) 
			return "";

		for (size_t i = 0; i < sz / 2; i++) 
		{
			if (palindrome[i] > 'a')
			{
				palindrome[i] = 'a';
				return palindrome;
			}
		}

		palindrome[sz - 1] = 'b';
		return palindrome;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->breakPalindrome("abccba");
	delete solution;
	system("pause");
	return 0;
}