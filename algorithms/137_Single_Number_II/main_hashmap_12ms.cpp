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
        unordered_map<int, int> map;
        for (auto &n : nums) {
            if (map.count(n)) {
                if (map[n] == 2)
                    map.erase(n);
                else
                    map[n]++;
            }
            else
                map[n] = 1;
        }
        return (*map.begin()).first;
    }
};

int main()
{
    Solution * solution = new Solution();
    vector<int> input = {2,2,3,2};
    auto result = solution->singleNumber(input);
    delete solution;
    cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
