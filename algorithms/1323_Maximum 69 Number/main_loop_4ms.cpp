//Given a positive integer num consisting only of digits 6 and 9.
//
//Return the maximum number you can get by changing at most one digit(6 becomes 9, and 9 becomes 6).

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
	int maximum69Number(int num) {
		string s = to_string(num);
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '6')
			{
				s[i] = '9';
				return stoi(s);
			}
		}
		return stoi(s);
	}
};

int main()
{
	Solution* solution = new Solution;
	
	delete solution;
	system("pause");
	return 0;
}