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
    int compareVersion(string v1, string v2) {
        int i = 0, j = 0, n1 = v1.size(), n2 = v2.size();
        while (i < n1 || j < n2) {
            int a = 0, b = 0;
            while (i < n1 && v1[i] != '.') {
                a = a * 10 + (v1[i++] - '0');
            }
            while (j < n2 && v2[j] != '.') {
                b = b * 10 + (v2[j++] - '0');
            }
            if (a > b)
                return 1;
            else if (a < b)
                return -1;
            ++i;
            ++j;
        }
        return 0;
    }
};

int main()
{
    Solution * solution = new Solution();
    if (solution->compareVersion("1.0", "1") != 0)
        throw;
    if (solution->compareVersion("01", "1") != 0)
        throw;
    if (solution->compareVersion("0.1", "1.1") != -1)
        throw;
    if (solution->compareVersion("1.0.1", "1") != 1)
        throw;
    if (solution->compareVersion("7.5.2.4", "7.5.3") != -1)
        throw;
    if (solution->compareVersion("1.0", "1.0.0") != 0)
        throw;
    if (solution->compareVersion("1.01", "1.001") != -1)
        throw;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
