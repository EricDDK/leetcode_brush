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
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        vector<int> out, visited(num.size(), 0);
        permuteDFS(num, 0, visited, out, res);
        return res;
    }
    
    void permuteDFS(vector<int>& num, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res)
    {
        if (level == num.size())
        {
            res.push_back(out);
            return;
        }
        for (int i = 0; i < num.size(); ++i) {
            if (visited[i] == 1) continue;
            visited[i] = 1;
            out.push_back(num[i]);
            permuteDFS(num, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
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
