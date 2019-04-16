//Given an array nums and a value val, remove all instances of that value in - place and return the new length.
//
//Do not allocate extra space for another array, you must do this by modifying the input array in - place with O(1) extra memory.
//
//The order of elements can be changed.It doesn't matter what you leave beyond the new length.

#include "iostream"
#include <vector>
#include <unordered_map>
#include <hash_set>
#include "windows.h"
#include "algorithm"
#include <stack>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int strSize = haystack.size();
		int patternSize = needle.size();
		if (strSize == 0 && patternSize == 0)
		{
			return 0;
		}
		if (strSize < patternSize)
		{
			return -1;
		}
		for (int i = 0; i <= strSize - patternSize; i++)
		{
			int j = 0;
			for (j=0; j < patternSize; j++)
			{
				if (haystack[i+j] != needle[j])
				{
					break;
				}
			}
			if (j == patternSize)
			{
				return i;
			}
			
		}
		return -1;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->strStr("aabaaabaaac","aabaaac");
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
