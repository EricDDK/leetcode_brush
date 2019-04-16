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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (auto str : strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            map[tmp].push_back(str);
        }
        vector<vector<string>> result;
        for (auto m : map) {
            result.push_back(m.second);
        }
        return result;
    }
};

int main()
{
    Solution* solution = new Solution;
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = solution->groupAnagrams(input);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
