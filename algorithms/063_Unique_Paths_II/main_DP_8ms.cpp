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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
            return 0;
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<long>> map(row + 1, vector<long>(col + 1, 0));
        map[0][1] = 1;
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                if (obstacleGrid[i - 1][j - 1] != 0)
                    continue;
                map[i][j] = map[i-1][j] + map[i][j-1];
            }
        }
        return map[row][col];
    }
};

int main()
{
    Solution* solution = new Solution;
    vector<vector<int>> input = {
        {0,0,0},
        {0,1,0},
        {0,0,0},
    };
    auto result = solution->uniquePathsWithObstacles(input);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
