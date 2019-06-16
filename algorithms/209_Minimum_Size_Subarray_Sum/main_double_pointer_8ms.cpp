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
        int left = 0, right = 0, size = nums.size(), result = size + 1, sum = 0;
        if (size <= 1) {
            return 0;
        }
        while (right < size) {
            while (sum < s && right < size) {
                sum += nums[right++];
            }
            while (sum >= s) {
                result = min(result, right - left);
                sum -= nums[left++];
            }
        }
        return result == size + 1 ? 0 : result;
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
