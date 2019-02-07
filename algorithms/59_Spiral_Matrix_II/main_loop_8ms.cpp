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
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) {
            return {};
        }
        vector<vector<int>> result(n, vector<int>(n, 0));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int value = 1;
        while (true) {
            for (int i = left; i <= right; ++i) {
                result[top][i] = value++;
            }
            if (++top > bottom) {
                break;
            }
            for (int i = top; i <= bottom; ++i) {
                result[i][right] = value++;
            }
            if (--right < left) {
                break;
            }
            for (int i = right; i >= left; --i) {
                result[bottom][i] = value++;
            }
            if (--bottom < top) {
                break;
            }
            for (int i = bottom; i >= top; --i) {
                result[i][left] = value++;
            }
            if (++left > right) {
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution* solution = new Solution;
    auto result = solution->generateMatrix(3);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
