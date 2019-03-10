//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

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
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> tmp(k, 0);
        int i = 0;
        while (i >= 0) {
            tmp[i]++;
            if (tmp[i] > n) {
                --i;
            }
            else if (i == k - 1) {
                result.push_back(tmp);
            }
            else {
                ++i;
                tmp[i] = tmp[i - 1];
            }
        }
        return result;
    }
};

int main()
{
    Solution* solution = new Solution;
    auto result = solution->combine(4, 2);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
