//Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.

//In one operation, you can choose any character of the string and change it to any other uppercase English character.

//Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.

//Note:
//Both the string's length and k will not exceed 104.

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
    int characterReplacement(string s, int k) {
        int result = 0, start = 0;
        int maxCnt = 0;
        vector<int> counts(26, 0);
        for (int i = 0; i < s.size(); ++i)
        {
            counts[s[i] - 'A']++;
            maxCnt = max(maxCnt, counts[s[i] - 'A']);
            while (i - start + 1 - maxCnt > k)
            {
                counts[s[start] - 'A']--;
                ++start;
            }
            result = max(result, i - start + 1);
        }
        return result;
    }
};

int main()
{
	Solution* solution = new Solution;
	
	delete solution;
	system("pause");
	return 0;
}