//Given a collection of intervals, merge all overlapping intervals.

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

struct Interval {
    int start;
    int end;
    Interval():start(0), end(0){};
    Interval(int s, int e):start(s), end(e){};
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        map<int, int> terminals;
        for (auto& i : intervals){
            terminals[i.start] += 1;
            terminals[i.end] -= 1;
        }
        
        vector<Interval> res;
        int levels = 0, start;
        for (auto& p : terminals){
            int x = p.first, cnt = p.second;
            if (levels == 0)
                start = x;
            levels += cnt;
            if (levels == 0){
                res.push_back(Interval(start, x));
            }
        }
        
        return res;
    }
};


int main()
{
    Solution* solution = new Solution;
    vector<Interval> input;
    input.push_back(Interval(1,4));
    input.push_back(Interval(0,2));
    input.push_back(Interval(3,5));
//    input.push_back(Interval(15,18));
    auto result = solution->merge(input);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
