//Given an input string, reverse the string word by word.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
	string reverseWords(string s) {
		int storeIndex = 0, n = s.size();
		reverse(s.begin(), s.end());
		for (int i = 0; i < n; ++i) 
		{
			if (s[i] != ' ') 
			{
				if (storeIndex != 0) 
					s[storeIndex++] = ' ';
				int j = i;
				while (j < n && s[j] != ' ') 
					s[storeIndex++] = s[j++];
				reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
				i = j;
			}
		}
		s.resize(storeIndex);
		return s;
	}

};

int main() {
	Solution* solution = new Solution;
	if (solution->reverseWords("the sky is blue") != "blue is sky the")
		throw;
	if (solution->reverseWords("  hello world!  ") != "world! hello")
		throw;
	if (solution->reverseWords("a good   example") != "example good a")
		throw;
	if (solution->reverseWords("a") != "a")
		throw;
	if (solution->reverseWords("1 ") != "1")
		throw;
	delete(solution);
	system("pause");
	return 0;
}