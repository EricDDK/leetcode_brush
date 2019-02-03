//Given a collection of distinct integers, return all possible permutations.

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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res{{}};
        for (auto &num : nums)
        {
            for (int k = res.size(); k > 0; --k) {
                vector<int> tmp = res.front();
                res.erase(res.begin());
                for (int i = 0; i <= tmp.size(); ++i) {
                    vector<int> one = tmp;
                    one.insert(one.begin() + i, num);
                    res.push_back(one);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution* solution = new Solution;
    vector<int> input = {1, 2, 3};
    auto result = solution->permute(input);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
