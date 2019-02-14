//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
//How many possible unique paths are there?

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
        vector<vector<int>> map(n, vector<int>(m, 1));
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                map[i][j] = map[i - 1][j] + map[i][j - 1];
            }
        }
        return map[n - 1][m - 1];
    }
};

int main()
{
    Solution* solution = new Solution;
    auto result = solution->uniquePaths(7, 3);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
