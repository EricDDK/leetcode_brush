//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//Note: For the purpose of this problem, we define empty string as valid palindrome.

#include "iostream"
#include <vector>
#include <unordered_map>
#include <map>
#include <hash_set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			while (!isAlphaNum(s[left]) && left < right)
			{
				left++;
			}
			while (!isAlphaNum(s[right]) && left < right)
			{
				right--;
			}
			if (toupper(s[left++]) != toupper(s[right--]))
			{
				return false;
			}
		}
		return true;
	}
	bool isAlphaNum(char &ch) {
		if (ch >= 'a' && ch <= 'z') return true;
		if (ch >= 'A' && ch <= 'Z') return true;
		if (ch >= '0' && ch <= '9') return true;
		return false;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->isPalindrome(".,");
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
