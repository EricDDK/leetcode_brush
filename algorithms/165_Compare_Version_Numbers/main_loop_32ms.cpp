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
        
        int left1 = 0, left2 = 0, right1 = 0, right2 = 0, n1 = v1.size(), n2 = v2.size();
        while (left1 < n1 || left2 < n2) {
            bool hasA = false, hasB = false;
            while (v1[right1] != '.' && right1 < n1) {
                hasA = true;
                right1++;
            }
            while (v2[right2] != '.' && right2 < n2) {
                hasB = true;
                right2++;
            }
            if (hasA != hasB) {
                return hasA == true ? 1 : -1;
            }
            if (left1 < right1 && left2 < right2) {
                while (v1[left1] == '0') {
                    left1++;
                }
                while (v2[left2] == '0') {
                    left2++;
                }
            }
            int a = 0, b = 0;
            while (left1 < right1) {
                a = a * 10 + (v1[left1] - '0');
                left1++;
            }
            while (left2 < right2) {
                b = b * 10 + (v2[left2] - '0');
                left2++;
            }
            if (a != b) {
                return a > b ? 1 : -1;
            }
            right1 = right1 == n1 ? right1 : right1 + 1;
            left1 = right1 == n1 ? left1 : left1 + 1;
            right2 = right2 == n2 ? right2 : right2 + 1;
            left2 = right1 == n1 ? left2 : left2 + 1;
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
    if (solution->compareVersion("1.0", "1.0.0") != -1)
        throw;
    if (solution->compareVersion("1.01", "1.001") != -1)
        throw;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
