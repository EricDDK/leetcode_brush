//Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

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
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum = (nums[j] >> i) & 1;
            }
            result |= (sum % 3) << i;
        }
        return result;
    }
};

int main()
{
    Solution * solution = new Solution();
    vector<int> input = {0,1,0,1,0,1,99};
    auto result = solution->singleNumber(input);
    delete solution;
    cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
