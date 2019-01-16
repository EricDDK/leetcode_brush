//Write a function that takes a string as input and reverse only the vowels of a string.

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
	string reverseVowels(string s) {
		int left = 0;
		int right = s.size() - 1;
		while (left < right)
		{
			while (left < right && !isVowel(s[left]))
			{
				left++;
			}
			while (left < right && !isVowel(s[right]))
			{
				right--;
			}
			swap(s[left], s[right]);
			left++; 
			right--;
		}
		return s;
	}

	bool isVowel(char c)
	{
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->reverseVowels("leetcode");
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}