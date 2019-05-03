//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.

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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> out;
        partitionDFS(s, result, out, 0);
        return result;
    }
    
    void partitionDFS(string s, vector<vector<string>> &result, vector<string> &out, int index) {
        if (index == s.size()) {
            result.push_back(out);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            if (!isPalindrome(s.substr(index, i - index + 1)))
                continue;
            out.push_back(s.substr(index, i - index + 1));
            partitionDFS(s, result, out, i + 1);
            out.pop_back();
        }
    }
    
    bool isPalindrome(string str) {
        if (str.empty())
            return false;
        if (map.count(str)) {
            return map[str];
        }
        int left = 0, right = (int)str.size() - 1;
        while (left <= right) {
            if (str[left] != str[right]) {
                map[str] = false;
                return false;
            }
            left++;
            right--;
        }
        map[str] = true;
        return true;
    }
    
private:
    unordered_map<string, bool> map;
};

int main()
{
    Solution * solution = new Solution();
    auto result = solution->partition("aab");
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
