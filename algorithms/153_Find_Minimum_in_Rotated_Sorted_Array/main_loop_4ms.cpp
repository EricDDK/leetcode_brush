//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
//Find the minimum element.
//
//You may assume no duplicate exists in the array.

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
    int findMin(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                return nums[i + 1];
            }
        }
        return nums[0];
    }
};

int main()
{
    Solution * solution = new Solution();
    vector<int> input = {3,4,5,1,2};
    auto result = solution->findMin(input);
    delete solution;
    cout << result << endl;
    if (solution->findMin(input) != 1)
        throw;
    input = {4,5,6,7,0,1,2};
    if (solution->findMin(input) != 0)
        throw;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
