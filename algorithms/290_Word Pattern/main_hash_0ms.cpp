//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non - empty word in str.

#include<sstream>
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
	bool wordPattern(string pattern, string str) {
		unordered_map<char, int> m1;
		unordered_map<string, int> m2;
		istringstream in(str);
		int i = 0;
		for (string word; in >> word; ++i) 
		{
			if (m1.find(pattern[i]) != m1.end() || m2.find(word) != m2.end()) 
			{
				if (m1[pattern[i]] != m2[word]) return false;
			}
			else 
			{
				m1[pattern[i]] = m2[word] = i + 1;
			}
		}
		return i == pattern.size();
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->wordPattern("abba", "dog dog dog dog");
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}