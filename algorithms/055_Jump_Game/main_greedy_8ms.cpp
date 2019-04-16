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
    bool canJump(vector<int>& nums) {
        int n = nums.size(), reach = 0;
        for (int i = 0; i < n; ++i) {
            if (reach >= n - 1 || reach < i) {
                break;
            }
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;
    }
};

int main()
{
    Solution* solution = new Solution;
    vector<int> input = {2,3,1,1,4};
    auto result = solution->canJump(input);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
