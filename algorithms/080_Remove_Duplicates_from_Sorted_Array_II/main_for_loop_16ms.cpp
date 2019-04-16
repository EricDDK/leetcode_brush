//Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
//
//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

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
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int count = 1;
        int last = nums[0];
        int result = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (count < 2) {
                if (last == nums[i]) {
                    count++;
                    nums[result] = nums[i];
                    result++;
                }
                else {
                    last = nums[i];
                    count = 1;
                    nums[result] = nums[i];
                    result++;
                }
            }
            else {
                if (last == nums[i]) {
                    count++;
                }
                else {
                    last = nums[i];
                    count = 1;
                    nums[result] = nums[i];
                    result++;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution* solution = new Solution;
    vector<int> input = {0,0,1,1,1,1,2,3,3};
    auto result = solution->removeDuplicates(input);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
