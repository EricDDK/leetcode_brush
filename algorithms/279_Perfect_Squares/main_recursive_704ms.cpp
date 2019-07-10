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
        int result = n, num = 2;
        while (num * num <= n) {
            int a = n / (num * num);
            int b = n % (num * num);
            result = min(result, a + numSquares(b));
            ++num;
        }
        return result;
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
