//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

#include "iostream"
#include <vector>
#include <unordered_map>
#include "windows.h"

using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		if (nRows <= 1) return s;
		string res = "";
		int size = 2 * nRows - 2;
		for (int i = 0; i < nRows; ++i) {
			for (int j = i; j < s.size(); j += size) {
				res += s[j];
				int tmp = j + size - 2 * i;
				if (i != 0 && i != nRows - 1 && tmp < s.size()) res += s[tmp];
			}
		}
		return res;
	}
};

int main()
{
	Solution* solution = new Solution;
	string str = "babad";
	auto result = solution->convert("PAYPALISHIRING",3);
	delete solution;
	system("pause");
	return 0;
}
