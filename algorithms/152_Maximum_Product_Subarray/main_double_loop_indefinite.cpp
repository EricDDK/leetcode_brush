//Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

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
    int maxProduct(vector<int>& nums) {
        long long result = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            long long maxP = nums[i];
            if (nums[i] == 0)
                continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == 0)
                    continue;
                maxP *= nums[j];
                result = max(result, maxP);
            }
            result = max(result, maxP);
        }
        return (int)result;
    }
};

int main()
{
    Solution * solution = new Solution();
    vector<int> input = {2,3,-2,4};
    auto result = solution->maxProduct(input);
    delete solution;
    cout << result << endl;
    if (solution->maxProduct(input) != 6)
        throw;
    input = {-2,3,-4};
    if (solution->maxProduct(input) != 24)
        throw;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
