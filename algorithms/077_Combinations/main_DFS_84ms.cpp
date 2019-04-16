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
        vector<int> out;
        combineDFS(result, out, n ,k, 1);
        return result;
    }
    
    void combineDFS(vector<vector<int>> &result, vector<int> &tmp, int n, int k, int index) {
        if (tmp.size() == k) {
            result.push_back(tmp);
            return;
        }
        for (int i = index; i <= n; ++i) {
            tmp.push_back(i);
            combineDFS(result, tmp, n, k, i + 1);
            tmp.pop_back();
        }
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
