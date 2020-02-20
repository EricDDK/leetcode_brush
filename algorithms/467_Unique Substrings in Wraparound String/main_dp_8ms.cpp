//Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//
//Now we have another string p.Your job is to find out how many unique non - empty substrings of p are present in s.In particular, your input is the string p and you need to output the number of different non - empty substrings of p in the string s.
//
//Note : p consists of only lowercase English letters and the size of p might be over 10000.

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
	int findSubstringInWraproundString(string p) {
		vector<int> cnt(26, 0);
		int len = 0;
		for (int i = 0; i < p.size(); ++i)
		{
			if (i > 0 && (p[i] == p[i - 1] + 1 || p[i - 1] - p[i] == 25))
				++len;
			else
				len = 1;
			cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], len);
		}
		return accumulate(cnt.begin(), cnt.end(), 0);
	}
};

int main()
{
	Solution* solution = new Solution;
	
	delete solution;
	system("pause");
	return 0;
}