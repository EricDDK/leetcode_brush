//There are a total of n courses you have to take, labeled from 0 to n-1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
//
//There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

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

// DP
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.empty() ? 0 : nums[0];
        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }
    
    int rob(vector<int> &nums, int left, int right) {
        if (right - left <= 1)
            return nums[left];
        vector<int> dp(right, 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);
        for (int i = left + 2; i < right; ++i)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp.back();
    }
};

int main()
{
    Solution * solution = new Solution();
    vector<int> input = {2,3,2};
    if (solution->rob(input) != 3)
        throw;
    input = {1,2,3,1};
    if (solution->rob(input) != 4)
        throw;
    input = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    if (solution->rob(input) != 15)
        throw;
    delete solution;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
