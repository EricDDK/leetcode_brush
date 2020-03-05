//Given a string s consisting only of characters a, b and c.
//
//Return the number of substrings containing at least one occurrence of all these characters a, b and c.

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
	int cnt[3];
public:
	int numberOfSubstrings(string s) {
		int len = (int)s.length(), ans = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		for (int l = 0, r = -1; l<len;) 
		{
			while (r<len && !(cnt[0] >= 1 && cnt[1] >= 1 && cnt[2] >= 1)) 
			{
				if (++r == len) 
					break;
				cnt[s[r] - 'a']++;
			}
			ans += len - r;
			cnt[s[l++] - 'a']--;
		}
		return ans;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->numberOfSubstrings("abcabc");
	if (result != 10)
		throw;
	result = solution->numberOfSubstrings("ababbbc");
	if (result != 3)
		throw;
	delete solution;
	system("pause");
	return 0;
}