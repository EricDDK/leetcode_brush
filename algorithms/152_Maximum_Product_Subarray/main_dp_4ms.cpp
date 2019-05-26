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
        int result = nums[0];
        int size = nums.size();
        vector<int> f(size, 0), g(size, 0);
        f[0] = g[0] = nums[0];
        for (int i = 1; i < size; ++i) {
            f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
            g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
            result = max(result, f[i]);
        }
        return result;
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
