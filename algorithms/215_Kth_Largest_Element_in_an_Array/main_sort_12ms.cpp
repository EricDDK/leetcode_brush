//Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

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
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
        
    }
};

int main()
{
    Solution * solution = new Solution();
    vector<int> input = {3,2,1,5,6,4};
    if (solution->findKthLargest(input, 2) != 5)
        throw;
    input = {3,2,3,1,2,4,5,5,6};
    if (solution->findKthLargest(input, 4) != 4)
        throw;
    input = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    delete solution;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
