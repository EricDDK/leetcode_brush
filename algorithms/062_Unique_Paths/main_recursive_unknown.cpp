//Given a collection of intervals, merge all overlapping intervals.

#include<sstream>
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
    int uniquePaths(int m, int n) {
        int result = 0;
        uniquePathsDFS(m - 1, n - 1, 0, 0, result);
        return result;
    }
    
    void uniquePathsDFS(int m, int n, int col, int row, int &result) {
        if (col == n && row == m) {
            result++;
            return;
        }
        if (col > n || row > m) {
            return;
        }
        uniquePathsDFS(m, n, col + 1, row, result);
        uniquePathsDFS(m, n, col, row + 1, result);
    }
};

int main()
{
    Solution* solution = new Solution;
    auto result = solution->uniquePaths(51, 9);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
