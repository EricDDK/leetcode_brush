//Given a non - empty string containing an out - of - order English representation of digits 0 - 9, output the digits in ascending order.
//
//Note:
//Input contains only lowercase English letters.
//Input is guaranteed to be valid and can be transformed to its original digits.That means invalid inputs such as "abc" or "zerone" are not permitted.
//Input length is less than 50, 000.

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

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Solution {
public:
	string originalDigits(string s) {
		vector<int> a(10, 0);
		vector<int> alpha(128, 0);
		for (char c : s)
			alpha[c]++;
		a[0] = alpha['z'];
		a[2] = alpha['w'];
		a[4] = alpha['u'];
		a[6] = alpha['x'];
		a[8] = alpha['g'];
		a[3] = alpha['h'] - a[8];
		a[5] = alpha['f'] - a[4];
		a[7] = alpha['v'] - a[5];
		a[1] = alpha['o'] - a[0] - a[2] - a[4];
		a[9] = alpha['i'] - a[5] - a[6] - a[8];
		string ans;
		for (int i = 0; i < 10; i++) {
			if (a[i] > 0)
				ans += string(a[i], '0' + i);
		}
		return ans;
	}
};
int main()
{
	Solution* solution = new Solution;
	auto result = solution->originalDigits("owoztneoer");
	if (result != "012")
		throw;
	result = solution->originalDigits("fviefuro");
	if (result != "45")
		throw;
	delete solution;
	system("pause");
	return 0;
}