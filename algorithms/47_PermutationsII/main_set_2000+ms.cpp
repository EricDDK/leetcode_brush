//Given a collection of numbers that might contain duplicates, return all possible unique permutations.

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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res{{}};
        for (auto &num : nums) {
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
        set<vector<int>> result;
        for (auto &r : res){
            result.insert(result.begin(), r);
        }
        return vector<vector<int>> (result.begin(), result.end());
    }
};

int main()
{
    Solution* solution = new Solution;
    vector<int> input = {1,1,2};
    auto result = solution->permuteUnique(input);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
