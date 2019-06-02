//Compare two version numbers version1 and version2.
//If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
//
//You may assume that the version strings are non-empty and contain only digits and the . character.
//
//The . character does not represent a decimal point and is used to separate number sequences.
//
//For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
//You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int s1 = numerator >= 0 ? 1 : -1;
        int s2 = denominator >= 0 ? 1 : -1;
        long long num = abs( (long long)numerator );
        long long den = abs( (long long)denominator );
        long long out = num / den;
        long long rem = num % den;
        unordered_map<long long, int> m;
        string res = to_string(out);
        if (s1 * s2 == -1 && (out > 0 || rem > 0)) res = "-" + res;
        if (rem == 0) return res;
        res += ".";
        string s = "";
        int pos = 0;
        while (rem != 0) {
            if (m.find(rem) != m.end()) {
                s.insert(m[rem], "(");
                s += ")";
                return res + s;
            }
            m[rem] = pos;
            s += to_string((rem * 10) / den);
            rem = (rem * 10) % den;
            ++pos;
        }
        return res + s;
    }
};

int main()
{
    Solution * solution = new Solution();
    if (solution->fractionToDecimal(1,2) != "0.5")
        throw;
    if (solution->fractionToDecimal(2,1) != "2")
        throw;
    if (solution->fractionToDecimal(2,3) != "0.(6)")
        throw;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
