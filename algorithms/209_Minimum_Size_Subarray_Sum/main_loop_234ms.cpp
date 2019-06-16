//Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

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
    int minSubArrayLen(const int s, vector<int>& nums) {
        int cur = 0, result = INT_MAX, i,j;
        for (i = 0; i < nums.size(); ++i) {
            cur = 0;
            for (j = i; j < nums.size(); ++j) {
                cur += nums[j];
                if (cur >= s) {
                    result = min(j - i + 1, result);
                    break;
                }
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};

int main()
{
    Solution * solution = new Solution();
    vector<int> input = {2,3,1,2,4,3};
    if (solution->minSubArrayLen(7, input) != 2)
        throw;
    input = {100};
    if (solution->minSubArrayLen(7, input) != 0)
        throw;
    input = {};
    if (solution->minSubArrayLen(100, input) != 0)
        throw;
    delete solution;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
