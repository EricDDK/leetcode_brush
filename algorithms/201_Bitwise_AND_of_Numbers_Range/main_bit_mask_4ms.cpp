//Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

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
    int rangeBitwiseAnd(int m, int n) {
        int mask = INT32_MAX;
        while ((m & mask) != (n & mask)) {
            mask <<= 1;
        }
        return m & mask;
    }
};

int main()
{
    Solution * solution = new Solution();
    if (solution->rangeBitwiseAnd(5, 7) != 4)
        throw;
    if (solution->rangeBitwiseAnd(0, 1) != 0)
        throw;
    delete solution;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
