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
		int m = haystack.length(), n = needle.length();
		if (!n) {
			return 0;
		}
		vector<int> lps = kmpProcess(needle);
		for (int i = 0, j = 0; i < m;) {
			if (haystack[i] == needle[j]) {
				i++;
				j++;
			}
			if (j == n) {
				return i - j;
			}
			if ((i < m) && (haystack[i] != needle[j])) {
				if (j) {
					j = lps[j - 1];
				}
				else {
					i++;
				}
			}
		}
		return -1;
	}
private:
	vector<int> kmpProcess(string& needle) {
		int n = needle.length();
		vector<int> lps(n, 0);
		for (int i = 1, len = 0; i < n;) {
			if (needle[i] == needle[len]) {
				lps[i++] = ++len;
			}
			else if (len) {
				len = lps[len - 1];
			}
			else {
				lps[i++] = 0;
			}
		}
		return lps;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->strStr("aabaaabaaac", "aabaaac");
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
