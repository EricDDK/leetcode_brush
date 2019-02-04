//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        vector<int> result;
        int col = matrix[0].size();
        int row = matrix.size();
        int cycleCount = row > col ? (col + 1) / 2 : (row + 1) / 2;
        for (int i = 0; i < cycleCount; ++i, col -= 2, row -= 2) {
            for (int c = i; c < i + col; ++c) {
                result.push_back(matrix[i][c]);
            }
            for (int r = i + 1; r < i + row; ++r) {
                result.push_back(matrix[r][i + col - 1]);
            }
            if (col <= 1 || row <= 1) {
                break;
            }
            for (int c = i + col - 2; c >= i; --c) {
                result.push_back(matrix[i + row - 1][c]);
            }
            for (int r = i + row - 2; r > i; --r) {
                result.push_back(matrix[r][i]);
            }
        }
        return result;
    }
};

int main()
{
    Solution* solution = new Solution;
    vector<vector<int>> input = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    auto result = solution->spiralOrder(input);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
