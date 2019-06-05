//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
//Write a function to find all the 10 - letter - long sequences(substrings) that occur more than once in a DNA molecule.

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
#include <functional>

using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		if (s.size() <= 10) 
			return result;
		int mask = 0x7ffffff, cur = 0;
		unordered_map<int, int> map;
		for (int i = 0; i < 9; ++i)
		{
			cur = (cur << 0x03) | (s[i] & 0x07);  // 0111
		}
		for (int i = 9; i < s.size(); ++i)
		{
			cur = ((cur & mask) << 3) | (s[i] & 7);
			if (map.count(cur)) 
			{
				if (map[cur] == 1)
					result.push_back(s.substr(i - 9, 10));
				++map[cur];
			}
			else 
			{
				map[cur] = 1;
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	if (solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT") != vector<string>{ "AAAAACCCCC", "CCCCCAAAAA" })
		throw;
	if (solution.findRepeatedDnaSequences("") != vector<string>{})
		throw;
	system("pause");
	return 0;
}