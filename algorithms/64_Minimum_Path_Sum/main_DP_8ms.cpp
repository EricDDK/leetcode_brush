//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.

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
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int result[row][col];
        result[0][0] =grid[0][0];
        for (int i = 1; i < col; ++i) {
            result[0][i] = grid[0][i] + result[0][i - 1];
        }
        for (int i = 1; i < row; ++i) {
            result[i][0] = grid[i][0] + result[i-1][0];
        }
        for (int i = 1; i < col; ++i) {
            for (int j = 1; j < row; ++j) {
                result[j][i] = grid[j][i] + min(result[j - 1][i], result[j][i - 1]);
            }
        }
        return result[row - 1][col - 1];
    }
};

int main()
{
    Solution* solution = new Solution;
    vector<vector<int>> input = {
        {1,2,5},
        {3,2,1}
    };
    auto result = solution->minPathSum(input);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
