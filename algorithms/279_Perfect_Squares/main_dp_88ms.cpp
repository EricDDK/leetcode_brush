//Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

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
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int minT = INT_MAX;
            int j = 1;
            while(i - j*j >= 0) {
                minT = min(minT, dp[i - j * j] + 1);
                ++j;
            }
            dp[i] = minT;
        }
        return dp.back();
    }
};

int main()
{
    Solution * solution = new Solution();
    if (solution->numSquares(12) != 3) {
        throw;
    }
    if (solution->numSquares(13) != 2) {
        throw;
    }
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
