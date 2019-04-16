//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
//Now consider if some obstacles are added to the grids. How many unique paths would there be?

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
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int result = INT_MAX;
        int col = grid[0].size(), row = grid.size();
        minPathSumDFS(grid, result, 0, 0, row, col, 0);
        return result;
    }
    
    void minPathSumDFS(vector<vector<int>>& grid, int& result, int m, int n, int row, int col, int tmpResult) {
        if (m >= row || n >= col) {
            return;
        }
        if (m == row -1 && n == col - 1) {
            result = min(tmpResult + grid[m][n], result);
            return;
        }
        minPathSumDFS(grid, result, m + 1, n, row, col, tmpResult + grid[m][n]);
        minPathSumDFS(grid, result, m , n + 1, row, col, tmpResult + grid[m][n]);
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
